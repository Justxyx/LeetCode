//
// Created by 肖应雄 on 2021/12/15.
//

#ifndef P2_P203_H
#define P2_P203_H
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *p,*temp;
        while (head->val == val && head != nullptr){
            p = head;
            if (head -> next != NULL){
                head = head->next;
            }
            else{
                head = nullptr;
            }
            delete p;
        }
        p = head;
        while (p->next != NULL){
            if (p->next->val == val){
                temp = p->next;
                p->next = temp->next;
                delete temp;
            } else{
                p = p->next;
            }
        }
        return head;
    }
};

#endif //P2_P203_H
