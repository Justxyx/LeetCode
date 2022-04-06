//
// Created by 肖应雄 on 2022/4/6.
//

#ifndef P7_P98_验证是否是搜索二叉树_H
#define P7_P98_验证是否是搜索二叉树_H

class Solution {
public:
    int max;
    int min;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left != nullptr){
            max = root->left->val;
            findMax(root->left);
            if (root->val <= max)
                return false;
        }
        if (root->right != nullptr){
            min = root->right->val;
            findMin(root->right);
            if (root->val >= min)
                return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }

    void findMax(TreeNode *node){
        if (node == nullptr)
            return;
        if (node->val > max)
            max = node->val;
        findMax(node->left);
        findMax(node->right);
    }

    void findMin(TreeNode *node){
        if (node == nullptr)
            return;
        if (node->val < min)
            min = node->val;
        findMin(node->left);
        findMin(node->right);
    }
};
#endif //P7_P98_验证是否是搜索二叉树_H
