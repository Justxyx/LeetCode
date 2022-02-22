//
// Created by 肖应雄 on 2022/2/22.
//

#ifndef P5_P142_H
#define P5_P142_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *virtualHead = new ListNode(0);
        virtualHead->next = head;


        ListNode *p1;
        ListNode *p2;

        p1 = virtualHead;
        p2 = virtualHead;
        ListNode *node = nullptr;
        while (p1 != nullptr && p2 != nullptr){
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == nullptr)
                break;
            p2 = p2->next;
            if (p1 == p2){
                node = p1;
                break;
            }
        }

        if (node == nullptr)
            return NULL;

        p1 = virtualHead;
        while ( p1 != node){
            p1 = p1->next;
            node = node->next;
        }
        return p1;
    }
};
#endif //P5_P142_H
