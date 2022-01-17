//
// Created by 肖应雄 on 2022/1/17.
//

#ifndef P2_P02_07_H
#define P2_P02_07_H

/**
 * 细心一点啊乖乖  很简单的一道理  题目不看仔细反复这么久！
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *pa = headA;
        ListNode *pb = headB;

        int countA = 0;
        int countB = 0;
        while (pa != nullptr){
            ++ countA;
            pa = pa->next;
        }
        while (pb != nullptr){
            ++ countB;
            pb = pb->next;
        }
        int deb = 0;
        countA > countB ? deb = countA - countB : deb = countB - countA;
        printf("%d",countA);
        printf("%d",countB);
        printf("%d",deb);
        printf("-------------");
        if (countA > countB){
            while (deb > 0){

                -- deb;
                headA = headA->next;
            }
        } else{


            while (deb > 0){
                -- deb;
                headB = headB->next;
            }
        }
        // printf("%d",headA->val);
        // printf("%d",headB->val);
        while (headA != NULL){
            if ( headA == headB){
                break;
            } else{
                headA = headA->next;
                if(headB == nullptr){
                    headA  = nullptr;
                    break;
                }
                headB = headB->next;
            }
        }
        return headA;
    }
};

#endif //P2_P02_07_H
