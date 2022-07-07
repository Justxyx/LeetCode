//
// Created by xm on 2022/7/7.
//

#ifndef P11_OFFER_MID_P06_从头到尾打印链表_H
#define P11_OFFER_MID_P06_从头到尾打印链表_H
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr) {
            ++ count;
            temp = temp->next;
        }
        cout << count << endl;
        vector<int> v(count,0);
        while (head != nullptr) {
            v[--count] = head->val;
            head = head->next;
        }
        return v;
    }
};
#endif //P11_OFFER_MID_P06_从头到尾打印链表_H
