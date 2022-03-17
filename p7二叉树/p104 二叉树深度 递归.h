//
// Created by 肖应雄 on 2022/3/17.
//

#ifndef P7_P104_二叉树深度_递归_H
#define P7_P104_二叉树深度_递归_H

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int lenLeft = 1 + maxDepth(root->left);
        int lenRight = 1 + maxDepth(root->right);
        int max = lenLeft > lenRight ? lenLeft:lenRight;
        return max;
    }
};
#endif //P7_P104_二叉树深度_递归_H
