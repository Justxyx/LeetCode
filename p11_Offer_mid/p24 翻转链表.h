//
// Created by xm on 2022/7/7.
//

#ifndef P11_OFFER_MID_P24_翻转链表_H
#define P11_OFFER_MID_P24_翻转链表_H
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *pre = nullptr;
        ListNode *next;
        while (head->next != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head->next = pre;
        return head;
    }
};
#endif //P11_OFFER_MID_P24_翻转链表_H
