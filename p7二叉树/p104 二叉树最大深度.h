//
// Created by 肖应雄 on 2022/3/15.
//

#ifndef P7_P104_二叉树最大深度_H
#define P7_P104_二叉树最大深度_H
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int max = 0;
        if (root == nullptr) return 0;
        queue.push(root);
        TreeNode *temp;
        while (!queue.empty()){
            ++ max;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                queue.pop();
                if (temp->right) queue.push(temp->right);
                if (temp->left) queue.push(temp->left);
            }
        }
        return max;
    }
};
#endif //P7_P104_二叉树最大深度_H
