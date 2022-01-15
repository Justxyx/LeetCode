//
// Created by 肖应雄 on 2022/1/15.
//

#ifndef P2_P24_H
#define P2_P24_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**         temp3  temp2
 *    pre   cur   cur.next  temp1
 *
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *virtualHead = new ListNode;
        virtualHead->next = head;
        ListNode *pre = virtualHead;
        ListNode *cur = head;
        ListNode *temp1 = nullptr;
        ListNode *temp2 = nullptr;
        ListNode *temp3 = nullptr;
        int count = 1;
        while (cur != nullptr ){

            if (count %2 == 1){
                temp3 = cur;
                temp2 = cur->next;
                temp1 = temp2->next;
                pre->next = temp2;
                temp2->next = temp3;
                temp3->next = temp1;
                pre = temp2;
            } else{
                pre = cur;
                cur = cur->next;
            }
            ++ count;
        }

        return virtualHead->next;
    }

};

#endif //P2_P24_H
