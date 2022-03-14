//
// Created by 肖应雄 on 2022/3/14.
//

#ifndef P7_P515_层次遍历_最大值_H
#define P7_P515_层次遍历_最大值_H

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode *temp;
        int max = 0;
        while (!queue.empty()){
            max = queue.front()->val;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                queue.pop();
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
                if (max < temp->val) max = temp->val;
            }
            res.push_back(max);
        }
        return res;
    }
};
#endif //P7_P515_层次遍历_最大值_H
