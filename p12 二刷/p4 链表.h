//
// Created by xm on 2022/10/2.
//

#ifndef P12__P4_链表_H
#define P12__P4_链表_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *pre, *cur;
        pre = temp;
        cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = pre->next;
            } else {
                pre = cur;
                cur = pre->next;
            }
        }
        return temp->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * pre, *cur;
        pre = nullptr;
        cur = head;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *cur = head;
        ListNode *pre, *end, *p1, *p2;
        pre = temp;
        while (cur != nullptr && cur->next != nullptr) {
            end = cur->next->next;
            p1 = cur;
            p2 = cur->next;
            pre->next = p2;
            p2->next = p1;
            p1->next = end;
            pre = p1;
            cur = end;
        }
        return temp->next;
    }
};

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;
        int count = 0;
        ListNode *p = head;
        while (count < n) {
            p = p->next;
            ++ count;
        }
        ListNode *p2 = head;
        ListNode *pre = p2;

        if (p == nullptr)
            return head->next;

        while (p != nullptr) {
            pre = p2;
            p2 = p2->next;
            p = p->next;
        }
        pre->next = p2->next;
        return head;
    }
};


class Solution07 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A = 0, len_B = 0;
        ListNode *p1 = headA, *p2 = headB;
        while (p1) {
            ++ len_A;
            p1 = p1->next;
        }

        while (p2) {
            ++ len_B;
            p2 = p2->next;
        }

        if (len_A > len_B) {
            int dump = len_A - len_B;
            while (dump > 0) {
                headA = headA->next;
                -- dump;
            }
        } else {
            int dump = len_B - len_A;
            while (dump > 0) {
                headB = headB->next;
                -- dump;
            }
        }

        while (headA != nullptr && headB != nullptr) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

class Solution142 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1, *p2;
        ListNode *vir = new ListNode(-1);
        vir->next = head;
        p1 = vir;
        p2 = vir;
        ListNode *meet = nullptr;

        while (p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != nullptr)
                p2 = p2->next;
            else
                return nullptr;

            if (p1 == p2) {
                break;
            }
        }

        if(p1 == nullptr || p2 == nullptr)
            return nullptr;

        p1 = vir;
        while (p1 != p2) {
            // cout << "p1:" << p1->val << endl;
            cout << "p2:" << p2->val << endl;
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};
#endif //P12__P4_链表_H
