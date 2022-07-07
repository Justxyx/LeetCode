//
// Created by xm on 2022/7/7.
//

#ifndef P11_OFFER_MID_H35_复制复杂链表_H
#define P11_OFFER_MID_H35_复制复杂链表_H

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        map<Node*, Node*> map;
        Node * temp = head;
        while (temp != nullptr) {
            map.insert(make_pair(temp, new Node(temp->val)));
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            map[temp]->next = map[temp->next];
            map[temp]->random = map[temp->random];
            temp = temp->next;
        }
        return map[head];
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node * temp = head;
        while (temp) {
            Node *node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }

        temp = head;
        while (temp) {
            if (temp->random == nullptr)
                temp->next->random = nullptr;
            else
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }



        Node *n1 = head;
        Node *n2 = head->next;
        temp = head->next;
        while (n2->next) {
            n1->next = n2->next;
            n2->next = n1->next->next;
            n1 = n1->next;
            n2 = n2->next;
        }
        n1->next = nullptr;

        while (head) {
            cout << head->val << endl;
            head = head->next;
        }
        // while (temp) {
        //     cout << temp->val << endl;
        //     temp = temp->next;
        // }


        return temp;
    }
};
#endif //P11_OFFER_MID_H35_复制复杂链表_H
