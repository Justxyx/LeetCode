//
// Created by 肖应雄 on 2022/1/17.
//




/**
 * 算法思想：
 *      1. 快慢指针找到焦点
 *      2. 焦点 头结点同时出发 相遇为循环结点
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

//        1. 寻找相交的结点
        ListNode *intersect = nullptr;
        while ( fast != nullptr && slow != nullptr){
            fast = fast->next;
            if (fast == nullptr){
                break;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow){
                intersect = fast;
                break;
            }
        }
        if (intersect == nullptr){
            return nullptr;
        }

//        2. 找到入口
        while ( head != intersect){
            head = head->next;
            intersect = intersect->next;
        }
        return intersect;
    }
};