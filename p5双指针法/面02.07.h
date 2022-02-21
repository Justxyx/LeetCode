//
// Created by 肖应雄 on 2022/2/21.
//

#ifndef P5_面02_07_H
#define P5_面02_07_H
/**
 * 这题目还挺坑的
 */
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
        A = headA;
        B = headB;
        if (lenA > lenB){
            count = lenA - lenB;
            while (count--)
                A = A->next;
        } else{
            count = lenB - lenA;
            while (count--)
                B = B->next;
        }
        // cout << A->val << endl;
        // cout << B->val << endl;
        while ( A != nullptr){
            if (A == B){
                return A;
            } else{
                A = A->next;
                B = B->next;
            }
        }
        return nullptr;
    }
};
#endif //P5_面02_07_H
