//
// Created by xm on 2022/7/29.
//

#ifndef P11_OFFER_MID_DAY_18_H
#define P11_OFFER_MID_DAY_18_H

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return max(left, right);
    }
};


class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (abs(lenNode(root->left) - lenNode(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int lenNode(TreeNode *node) {
        if (node == nullptr)
            return 0;
        int left = 1 + lenNode(node->left);
        int right = 1 + lenNode(node->right);
        return max(left, right);
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (isBalan(root) == -1)
            return false;
        else
            return true;
    }

    int isBalan(TreeNode *node) {
        if (node == nullptr)
            return 0;
        int left = isBalan(node->left);
        int right = isBalan(node->right);

        if (left == -1)
            return -1;
        if (right == -1)
            return -1;
        if (abs(left-right) > 1)
            return -1;


        return max(left, right) + 1;
    }
};
#endif //P11_OFFER_MID_DAY_18_H
