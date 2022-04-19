//
// Created by 肖应雄 on 2022/4/18.
//
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include "lst_timer.h"

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

static int pipefd[2];
static sort_timer_lst timer_lst;
static int epollfd = 0;

int setnonblocking(int fd){
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

void addfd(int epollfd,int fd){
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN|EPOLLET;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);

}

void sig_handler(int sig){
    int svae_error = errno;
    int msg = sig;
    send(pipefd[1],(char *)&msg,1,0);
    errno = svae_error;
}

void addsig(int sig){
    struct sigaction sa;
    memset(&sa,'\0',sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig,&sa,NULL) != -1);
}

/*
 * 定时器的回调函数 它删除非链接的socket上的注册事件 并关闭之
 */
void cb_func(client_data *user_data){
    epoll_ctl(epollfd,EPOLL_CTL_DEL,user_data->sockfd,0);
    close(user_data->sockfd);
    printf("close fd \n");
}

void timer_handler(){
    // 定时处理任务
    timer_lst.tick();
    // 重新定时 不断的触发sigalrm信号
    alarm(TIMESLOT);
}

int mian(int argc,char *argv[]){
    if (argc <= 2){
        perror("argc error");
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = port;
    inet_pton(AF_INET,ip,&address.sin_addr);

    int listenfd = socket(PF_INET,SOCK_STREAM,0);
    assert(listenfd >= 0);

    ret = bind(listenfd,(struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(listenfd,5);
    assert(ret != -1);

    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    assert(epollfd != -1 );
    addfd(epollfd,listenfd);

    ret = socketpair(PF_INET,SOCK_STREAM,0,pipefd);
    assert(ret != -1);

    setnonblocking(pipefd[1]);
    addfd(epollfd,pipefd[0]);

    /*
     * 设置信号处理函数
     */
    addsig(SIGALRM);
    addsig(SIGTERM);
    bool stop_server = false;
    /*
     *
// 用户的数据结构
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[ BUFFER_SIZE ];
    util_timer* timer;
};
     */
    client_data *users = new client_data[FD_LIMIT];
    bool timeout = false;
    alarm(TIMESLOT);  // 5  每间隔五秒 发送一个定时器信号

    while (!stop_server){
        int number = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
        if ((number < 0) && (errno != EINTR)){
            printf("epoll failure \n");
            break;
        }

        for (int i = 0; i < number; ++i) {
            int sockfd = events[i].data.fd;
            /*
             * 有新链接的客户端
             */
            if (sockfd == listenfd){

            struct  sockaddr_in client_address;
            socklen_t client_addrelength = sizeof(client_address);
            int connfd = accept(listenfd,(struct sockaddr*) &client_address,&client_addrelength);
            addfd(epollfd,connfd);
            users[connfd].address = client_address;
            users[connfd].sockfd = connfd;

            /*
             * 创建定时器
             */
            /*
             *     time_t expire;
    void (*cb_func)( client_data* );   // 任务超时时间 这里用绝对时间
    client_data* user_data; // 任务的回调函数
    util_timer* prev;  // 指向前一个
    util_timer* next;  // 指向后一个
             */

            util_timer *timer = new util_timer;
            timer->user_data = &users[connfd];
            timer->cb_func = cb_func;
            time_t cur = time(NULL);
            timer->expire = cur + 3 * TIMESLOT;
            users[connfd].timer = timer;
            timer_lst.add_timer(timer);
            }
            /*
             * 处理信号
             */
            else if ( (sockfd == pipefd[0]) && (events[i].events & EPOLLIN)){
                int sig;
                char signals[1024];
                ret = recv(pipefd[0],signals,sizeof(signals),0);
                if (ret == -1){
                    continue;
                } else if ( ret == 0){
                    continue;
                } else{
                    for (int j = 0; j < ret; ++j) {
                        switch (signals[j]) {
                            case SIGALRM:
                            {
                                timeout = true;
                                break;
                            }
                            case SIGTERM:{
                                stop_server = true;
                            }
                        }
                    }
                }
            }
            /*
             * 处理客户端链接上接受到的数据
             */
            else if ( events[i].events & EPOLLIN){
                memset(users[sockfd].buf,'\0',BUFFER_SIZE);
                ret = recv(sockfd,users[sockfd].buf,BUFFER_SIZE-1,0);
                util_timer *timer = users[sockfd].timer;
                if (ret < 0){
                    // 如果发生错误 则关闭链接 并移除对应的定时器
                    if ( errno != EAGAIN){
                        cb_func(&users[sockfd]);
                        if (timer){
                            timer_lst.del_timer(timer);
                        }
                    }
                } else if (ret == 0){
                    // 如果对方关闭链接 我们也关闭链接
                    cb_func(&users[sockfd]);
                    if (timeout){
                        timer_lst.del_timer(timer);
                    }
                } else{
                    // 如果某个客户端链接上有数据可读 我们需要调整对应的定时器 以延迟该链接的关闭时间
                    if (timer){
                        time_t cur = time(NULL);
                        timer->expire = cur + 3 + TIMESLOT;
                        timer_lst.adjust_timer(timer);
                    }
                }
            } else{
                // do others
            }
        }

        // 最后处理定时事件 因为IO时间具有更高的优先级  当然 这样这样也将导致定时任务不能精确的按照预期时间准确的执行
        if (timeout){
            timer_handler();
            timeout = false;
        }
    }

    close(listenfd);
    close(pipefd[1]);
    close(pipefd[0]);
    delete []users;
    return 0;

}

