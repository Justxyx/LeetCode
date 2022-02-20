//
// Created by 肖应雄 on 2022/2/20.
//

#ifndef P5_206_H
#define P5_206_H

/**
 *  好讨厌链表的题目
 *  这里还要刷
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

;


class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode *p1 = nullptr;
        ListNode *p2 = nullptr;
        ListNode *p3 = nullptr;

        p2 = head;
        while ( p2 ){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

#endif //P5_206_H
