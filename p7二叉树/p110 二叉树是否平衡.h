//
// Created by 肖应雄 on 2022/3/20.
//

#ifndef P7_P110_二叉树是否平衡_H
#define P7_P110_二叉树是否平衡_H

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftLen = lenDep(root->left);
        int rightLen = lenDep(root->right);
        if (abs(leftLen - rightLen) > 1) return false;


        bool b1 = isBalanced(root->left);
        bool b2 = isBalanced(root->right);
        return b1&&b2;
    }

    int lenDep(TreeNode *node){
        if (!node) return 0;
        int lenLeft = 1 + lenDep(node->left);
        int lenRight = 1 + lenDep(node->right);
        int lenMax = lenLeft > lenRight ? lenLeft:lenRight;
        return lenMax;
    }
};
#endif //P7_P110_二叉树是否平衡_H
