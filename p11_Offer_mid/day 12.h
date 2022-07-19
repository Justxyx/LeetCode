//
// Created by xm on 2022/7/19.
//

#ifndef P11_OFFER_MID_DAY_12_H
#define P11_OFFER_MID_DAY_12_H

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val > l2->val) {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *pre = l1;
        while (l1->next && l2) {
            if (l1->val <= l2->val && l1->next->val > l2->val) {
                ListNode *s1 = l1->next;
                ListNode *s2 = l2;
                l2 = l2->next;
                l1->next = s2;
                s2->next = s1;
                l1 = l1->next;
            } else {
                l1 = l1->next;
            }
        }
        if (l2 != nullptr)
            l1->next = l2;
        return pre;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a, len_b;
        ListNode *temp_a = headA;
        ListNode *temp_b = headB;
        while (temp_a) {
            ++ len_a;
            temp_a = temp_a->next;
        }
        while (temp_b) {
            ++ len_b;
            temp_b = temp_b->next;
        }

        int abss = abs(len_a - len_b);
        temp_a = headA;
        temp_b = headB;
        while (abss) {
            if (len_a > len_b)
                temp_a = temp_a->next;
            else
                temp_b = temp_b->next;
            --abss;
        }
        while (temp_a) {
            if (temp_a == temp_b)
                return temp_a;
            temp_a = temp_a->next;
            temp_b = temp_b->next;
        }
        return nullptr;
    }
};

#endif //P11_OFFER_MID_DAY_12_H
