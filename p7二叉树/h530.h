//
// Created by 肖应雄 on 2022/4/7.
//

#ifndef P7_H530_H
#define P7_H530_H


class Solution {
public:
    int min= 999999999;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left != nullptr){
            int res = abs(findLeft(root->left) - root->val);
            if (res < min)
                min = res;
        }
        if (root->right != nullptr){
            int res = abs(findRight(root->right) - root->val);
            if (res < min)
                min = res;
        }

        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        return min;
    }

    int findLeft(TreeNode *node){
        while (node->right != nullptr)
            node = node->right;
        return node->val;
    }

    int findRight(TreeNode *node){
        while (node->left != nullptr)
            node = node->left;
        return node->val;
    }
};
#endif //P7_H530_H
