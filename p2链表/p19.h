//
// Created by 肖应雄 on 2022/1/15.
//

#ifndef P2_P19_H
#define P2_P19_H


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *virtualHead = new ListNode;
        virtualHead->next = head;

        ListNode *cur = head;
        ListNode *preCur = virtualHead;
        ListNode *p = cur;
        for (int i = 1; i < n; ++i) {
            p = p->next;
        }
        while (p->next != nullptr){
            preCur = cur;
            cur = cur->next;
            p = p->next;
        }

        // delete cur
        preCur->next = cur->next;
        delete cur;
        return virtualHead->next;
    }
};

#endif //P2_P19_H
