//
// Created by 肖应雄 on 2022/4/18.
//

#ifndef LST_TIMER
#define LST_TIMER

#include <time.h>
#include <netinet/in.h>

#define BUFFER_SIZE 64
class util_timer;

/*
 * 用户数据结构
 */
struct client_data{
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer *time;
};

/*
 * 定时器类
 */

class util_timer{
public:
public:
    time_t expire;  // 任务的超时时间 绝对时间
    void (*cb_func)(client_data *);
    client_data *user_data;
    util_timer *prev;  // 指向上一个定时器
    util_timer *next;   // 指向下一个定时器
};

/*
 * 定时器类
 * 一个双向链表 有头结点与尾节点
 */
class sort_timer_lst{
public:
    sort_timer_lst(util_timer *head, util_timer *tail) : head(head), tail(tail) {}
    /*
     * 链表销魂 删除所有节点
     */
    ~sort_timer_lst(){
        util_timer *tmp = head;
        while (tmp){
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }

    /*
     * 为空
     */
    void add_timer(util_timer *timer){
        if (!timer){
            return;
        }
        if (!head){
            head = tail = timer;
            return;
        }

        /*
         * 如果目标定时器时间小于当前链表中所有的定时器超时时间，则把该定时器插入到链表头部
         * 否则 就要重载函数 add_timer 以保证链表的升序特性
         */

        if (timer->expire  < head->expire){
            timer->next = head;
            head->prev = timer;
            head = timer;
            return;
        }


    }

private:
    util_timer *head;
    util_timer *tail;
};

