//
// Created by 肖应雄 on 2022/3/15.
//

#ifndef P7_P117_H
#define P7_P117_H

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> queue;
        Node *pre,*next;
        queue.push(root);

        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                if (i == 0){
                    pre = queue.front();
                    pre->next = nullptr;
                    queue.pop();
                    if (pre->left) queue.push(pre->left);
                    if (pre->right) queue.push(pre->right);
                    continue;
                }
                next = queue.front();
                queue.pop();
                if (next->left) queue.push(next->left);
                if (next->right) queue.push(next->right);
                pre->next = next;
                next->next = nullptr;
                pre = next;
            }
        }
        return root;
    }
};
#endif //P7_P117_H
