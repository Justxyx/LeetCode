//
// Created by 肖应雄 on 2022/4/19.
//

#ifndef P8_LST_TIMER_H
#define P8_LST_TIMER_H
#ifndef LST_TIMER
#define LST_TIMER

#include <time.h>

#define BUFFER_SIZE 64
class util_timer;


// 用户的数据结构
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[ BUFFER_SIZE ];
    util_timer* timer;
};

// 定时器类
class util_timer
{
public:
    util_timer() : prev( NULL ), next( NULL ){}

public:
    time_t expire;
    void (*cb_func)( client_data* );   // 任务超时时间 这里用绝对时间
    client_data* user_data; // 任务的回调函数
    util_timer* prev;  // 指向前一个
    util_timer* next;  // 指向后一个
};

// 定时器双向列表 升序 双向列表  有头结点跟尾节点
class sort_timer_lst
{
public:
    // 默认构造函数
    sort_timer_lst() : head( NULL ), tail( NULL ) {}
    // 链表销毁时候，删除所、所有的定时器
    ~sort_timer_lst()
    {
        util_timer* tmp = head;
        while( tmp )
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }
    // 新增定时器
    void add_timer( util_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        if( !head )
        {
            head = tail = timer;
            return;
        }

        /*
        如果当前节点小于所有定时器时间 则插入头结点
        否则 调用重载函数add_timer
        */
        if( timer->expire < head->expire )
        {
            timer->next = head;
            head->prev = timer;
            head = timer;
            return;
        }
        add_timer( timer, head );
    }

    /*
    当某个定时器任务发生变化时，调整对应的定时器在链表中的位置  这个函数只考虑这个
    定时器超时时间延长的情况，即该定时器需要往链表尾部移动
    */
    void adjust_timer( util_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        util_timer* tmp = timer->next;
        // 如果在尾部 或者仍然小于下一个定时器的值 就不用调整
        if( !tmp || ( timer->expire < tmp->expire ) )
        {
            return;
        }
        // 若果是头结点 就取出 重新插入表中
        if( timer == head )
        {
            head = head->next;
            head->prev = NULL;
            timer->next = NULL;
            add_timer( timer, head );
        }
            //如果不是头结点 也不是尾节点  取出 重新插入表中
        else
        {
            timer->prev->next = timer->next;
            timer->next->prev = timer->prev;
            add_timer( timer, timer->next );
        }
    }
    // 删除一个节点 这里略掉
    void del_timer( util_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        if( ( timer == head ) && ( timer == tail ) )
        {
            delete timer;
            head = NULL;
            tail = NULL;
            return;
        }
        if( timer == head )
        {
            head = head->next;
            head->prev = NULL;
            delete timer;
            return;
        }
        if( timer == tail )
        {
            tail = tail->prev;
            tail->next = NULL;
            delete timer;
            return;
        }
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        delete timer;
    }

    /*
    SIGALRM 函数每次被触发，就在信号处理中执行一次tick函数
    */
    void tick()
    {
        if( !head )
        {
            return;
        }
        printf( "timer tick\n" );
        time_t cur = time( NULL );
        util_timer* tmp = head;
        while( tmp )
        {
            if( cur < tmp->expire )
            {
                break;
            }
            tmp->cb_func( tmp->user_data );
            head = tmp->next;
            if( head )
            {
                head->prev = NULL;
            }
            delete tmp;
            tmp = head;
        }
    }

private:
    /*
    一个函数重载 把节点加入到合适的地方
    */
    void add_timer( util_timer* timer, util_timer* lst_head )
    {
        util_timer* prev = lst_head;
        util_timer* tmp = prev->next;
        while( tmp )
        {
            if( timer->expire < tmp->expire )
            {
                prev->next = timer;
                timer->next = tmp;
                tmp->prev = timer;
                timer->prev = prev;
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        if( !tmp )
        {
            prev->next = timer;
            timer->prev = prev;
            timer->next = NULL;
            tail = timer;
        }

    }

private:
    util_timer* head;
    util_timer* tail;
};

#endif

#endif //P8_LST_TIMER_H
