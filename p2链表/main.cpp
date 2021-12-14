#include <iostream>
using namespace std;


// 单链表 结构
class ListNode{
public:
    int val;
    ListNode *next;
public:
    ListNode(int val) : val(val) ,next(NULL){}    // 节点构造函数
    ListNode(int val, ListNode *next) : val(val), next(next) {}   // 构造函数2
};
// 链表测试
void test(){
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *p,*temp;
        while (head->val == val && head != nullptr){
            p = head;
            if (head -> next != NULL){
                head = head->next;
            }
            else{
                head = nullptr;
            }
            delete p;
        }
        p = head;
        while (p->next != NULL){
            if (p->next->val == val){
                temp = p->next;
                p->next = temp->next;
                delete temp;
            } else{
                p = p->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode *temp;
    ListNode *head = new ListNode(0);
    temp = head;
    for (int i = 1; i < 10; ++i) {
        ListNode *n = new ListNode(7);
        temp->next = n;
        temp = n;
    }

    ListNode *n;
    Solution solution;
    solution.removeElements(n,7);
    while (head->next != nullptr){
        cout << head->val << ",";
        head = head->next;
    }
    return 0;
}
