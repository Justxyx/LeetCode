#include <iostream>
using namespace std;


class MyLinkedList{
public:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode(int val) :val(val), next(nullptr) {};
    };

    MyLinkedList() {
        _dummyHead = new LinkNode(0);
        _size = 0;
    }

    int get(int index){
        if ( index > (_size -1) || index < 0){
            return  -1;
        }
        LinkNode *cur = _dummyHead->next;
        while ( --index){
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val){
        LinkNode *newNode = new LinkNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        ++ _size;
    }

    void addAtTail(int val){
        LinkNode *newNode = new LinkNode(val);
        LinkNode *curNode = _dummyHead;
        while ( curNode->next != nullptr){
            curNode = curNode->next;
        }
        curNode->next = newNode;
        ++ _size;
    }

    // index 之前加入
    // 0 就是头结点   size 就是尾结点  大于size 就返回-1
    void addAtIndex(int index,int val){
        if (index > _size)
            return ;
        LinkNode *newNode = new LinkNode(val);
        LinkNode *curNode = _dummyHead->next;
        while ( index --){
            curNode = curNode->next;
        }
        curNode->next = newNode;
        ++ _size;
    }

    void deleteAtIndex(int index){
        if (index >= _size || index < 0)
            return;
        LinkNode *curNode = _dummyHead;
        while ( index --){
            curNode = curNode->next;
        }
        LinkNode *temp = curNode->next;
        curNode->next = curNode->next->next;
        delete temp;
        --_size;
    }

    void printLinkList(){
        LinkNode *cur = _dummyHead;
        while ( cur->next != nullptr){
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }


private:
    int _size;
    LinkNode *_dummyHead;    // 虚指针
};




