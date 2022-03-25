//
// Created by 肖应雄 on 2022/3/25.
//

#ifndef P7_H111_最小深度_递归_H
#define P7_H111_最小深度_递归_H

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (root->left == nullptr && root->right == nullptr) return 1;
        else if (root->left == nullptr) return right + 1;
        else if (root->right == nullptr) return left + 1;
        return min(left,right) + 1;
    }
};

#endif //P7_H111_最小深度_递归_H
