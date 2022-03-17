//
// Created by 肖应雄 on 2022/3/17.
//

#ifndef P7_H101_对称二叉树_H
#define P7_H101_对称二叉树_H

class Solution {
public:
    bool compare(TreeNode *left,TreeNode *right){
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr || right == nullptr) return false;
        else if (left->val != right->val) return false;

        bool b1 = compare(left->left,right->right);
        bool b2 = compare(left->right,right->left);
        bool res = b1*b2;
        return res;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left,root->right);
    }
};
#endif //P7_H101_对称二叉树_H
