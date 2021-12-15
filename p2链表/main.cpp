#include <iostream>
using namespace std;


//// 单链表 结构
//class ListNode{
//public:
//    int val;
//    ListNode *next;
//public:
//    ListNode(int val) : val(val) ,next(NULL){}    // 节点构造函数
//    ListNode(int val, ListNode *next) : val(val), next(next) {}   // 构造函数2
//};
//// 链表测试
//void test(){
//    ListNode *head = new ListNode(5);
//    head->next = new ListNode(2);
//}

/*
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

 */

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr) {}
    };
    MyLinkedList() {
        size = 0;
        fHead = new ListNode(0);
    }

    int get(int index) {
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        ListNode* cur = fHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        auto *p = new ListNode(val);
        p->next = fHead->next;
        fHead->next = p;
        ++ size;
    }

    void addAtTail(int val) {
        auto *p = new ListNode(val);
        auto *temp = fHead;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = p;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        if (index <= 0){
            // 作为头结点插入
            auto *p = new ListNode(val);
            p->next = fHead->next;
            fHead->next = p;
        } else{
        auto *temp = fHead;
        while (index>0){
            temp = fHead->next;
            -- index;
        }
        auto *f = new ListNode(val);
        f->next = temp->next;
        temp->next = f;
        }
        ++ size;
        return;
    }

    void deleteAtIndex(int index) {
        if (index < 0|| index > size-1)
            return;
        ListNode *p = fHead;
        ListNode *temp = p;
        while (index >= 0){
            temp = p;
            p = p->next;
        }
        temp->next = p->next;
        delete p;
        --size;
    }

private:
    ListNode *fHead;
    int size;
};

int main() {


    return 0;
}
