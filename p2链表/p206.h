//
// Created by 肖应雄 on 2022/1/14.
//

#ifndef P2_P206_H
#define P2_P206_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while (cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


#endif //P2_P206_H
