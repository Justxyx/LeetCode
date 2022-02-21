//
// Created by 肖应雄 on 2022/2/21.
//

#ifndef P5_P19_H
#define P5_P19_H

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *virtualHead = new ListNode(0,head);
        ListNode *p = virtualHead;
        ListNode *p2 = virtualHead;
        while ( n --){
            p2 = p2->next;
        }
        while (p2->next != nullptr){
            p = p->next;
            p2 = p2->next;
        }

        // delete p.next
        ListNode *temp = p->next;
        if (temp->next == nullptr)
            p->next = nullptr;
        else
            p->next = temp->next;

        delete(temp);
        return virtualHead->next;
    }
};

#endif //P5_P19_H
