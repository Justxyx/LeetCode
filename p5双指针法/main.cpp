#include <iostream>
using namespace std;
#include <vector>
#include <list>


 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int lenA = 0;
            int lenB = 0;
        ListNode *A = headA;
        ListNode *B = headB;
        while (A){
            ++ lenA;
            A = A->next;
        }
        while (B){
            ++ lenB;
            B = B->next;
        }
        int count = 0;
        if (lenA == 0 || lenB == 0)
            return nullptr;
        if (lenA > lenB){
            count = lenA - lenB;
            while (count--)
                A = A->next;
        } else{
            count = lenB - lenA;
            while (count--)
                B = B->next;
        }
        while ( A != nullptr){
            if (A->val == B->val){
                return A;
            } else{
                A = A->next;
                B = B->next;
            }
        }
        return nullptr;
    }
};




int main() {
    Solution solution;
    ListNode A(1);
    ListNode B(2);
    solution.getIntersectionNode(&A,&B);

    return 0;
}
