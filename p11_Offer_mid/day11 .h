//
// Created by xm on 2022/7/19.
//

#ifndef P11_OFFER_MID_DAY11_H
#define P11_OFFER_MID_DAY11_H

class Solution1 {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        if (head->val == val)
            return head->next;
        ListNode *temp = head;
        while (temp->next) {
            if (temp->next->val == val) {
                ListNode * s = temp->next->next;
                temp->next = s;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * temp = head;
        while (k) {
            temp = temp->next;
            --k;
        }

        while (temp) {
            head = head->next;
            temp = temp->next;
        }
        return head;
    }
};
#endif //P11_OFFER_MID_DAY11_H
