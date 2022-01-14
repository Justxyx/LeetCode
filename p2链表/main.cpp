#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head->next;
        ListNode *next = nullptr;
        ListNode *pre = head;
        ListNode *prePre = nullptr;

        ListNode *newHead = head;
        int count = 1;
        while (cur != nullptr){
            if (count %2 != 0){

                next = cur->next;
                pre->next = next;
                cur->next = pre;
                if ( prePre != nullptr){
                    prePre->next = cur;
                }
                prePre = pre;
                pre = cur;
                cur = next;

                if (count == 1){
                    newHead = prePre;
                }
            } else{
                cur = cur->next;
                prePre = pre;
                pre = cur;
            }
            ++ count;
        }
        return  newHead;
    }
};

int main() {

    return  0;
}
