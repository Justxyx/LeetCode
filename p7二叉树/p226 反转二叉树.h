//
// Created by 肖应雄 on 2022/3/16.
//

#ifndef P7_P226_反转二叉树_H
#define P7_P226_反转二叉树_H

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        reserve(root);
        return root;
    }

    void reserve(TreeNode *node){
        if (!node) return;
        if (node->left == nullptr && node->right == nullptr)
            return;
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        reserve(node->left);
        reserve(node->right);
    }
};
#endif //P7_P226_反转二叉树_H
