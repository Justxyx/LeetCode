//
// Created by 肖应雄 on 2022/4/18.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int timeout_connect(const char *ip,int port ,int time){
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = port;
    inet_pton(AF_INET,ip,&address.sin_addr);

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    assert(sockfd >= 0);

    struct timeval timeout;
    timeout.tv_sec = time;
    timeout.tv_usec = 0;
    socklen_t len = sizeof(timeout);

    ret = setsockopt(sockfd,SOL_SOCKET,SO_SNDLOWAT,&timeout,len);
    assert(ret != -1);

    ret = connect(sockfd,(struct sockaddr*)&address, sizeof(address));
    if (ret == -1){
        if (errno == EINPROGRESS){
            printf("connect timeout ...");
            return -1;
        }
        printf("error occur when connecting to server\n");
        return -1;
    }
}

int main(int argc,char* argv[]){
    if (argc <= 2){
        perror("argc error");
    }

    const char* ip = argv[1];
    int port  = atoi(argv[2]);

    int sockefd = timeout_connect(ip,port,10);
}