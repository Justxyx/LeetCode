//
// Created by 肖应雄 on 2022/4/19.
//

#include <ctime>

#define TIMEOUT 5000
int timeout = TIMEOUT;
time_t start = time(NULL);
time_t end = time(NULL);


int main()
{
    while (1){
        start = time(NULL);
        int number = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,timeout);

        // 如果epoll_wait成功返回0  说明超时时间到 此时可以处理定时任务 并重置定时时间
        if  (number == 0){
            timeout = TIMEOUT;
            continue;
        }

        // 如果epoll_wait的返回值大于0 则本次epoll_wait调用的持续时间是（end-start)*1000 ms  我们需要重新设置下次的超时时间
        timeout -= (end - start) * 1000;
        if  (timeout <= 0){
            timeout = TIMEOUT;
        }
    }
}