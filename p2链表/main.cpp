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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *p = nullptr;
        p = headA;
        while ( p != nullptr){
            p = p->next;
            ++ lenA;
        }
        p = headB;
        while ( p != nullptr){
            p = p->next;
            ++ lenB;
        }

        int deb = lenA - lenB;
        if (deb > 0){
            for (int i = 0; i < deb; ++i) {
                headA = headA->next;
            }
        } else{
            for (int i = 0; i < deb; ++i) {
                headB = headB->next;
            }
        }

        ListNode *temp = headA;
        int flag = 1;
        while (headA != nullptr){

        }

        if (flag){
            return temp;
        } else{
            return nullptr;
        }

    }
};

int main() {

    return  0;
}
