//
// Created by 肖应雄 on 2022/3/14.
//

#ifndef P7_P429_N叉树层次遍历_H
#define P7_P429_N叉树层次遍历_H

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<Node*> queue;
        queue.push(root);
        vector<int> parag;
        Node *temp;

        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                queue.pop();
                if (temp->children.size() != 0){
                    vector<Node*> chil = temp->children;
                    for (Node* item : chil)
                        queue.push(item);
                }
                parag.push_back(temp->val);
            }
            res.push_back(parag);
            parag.clear();
        }
        return res;
    }
};
#endif //P7_P429_N叉树层次遍历_H
