//
// Created by 肖应雄 on 2022/3/21.
//

#ifndef P7_P110_递归写法_一个递归函数_H
#define P7_P110_递归写法_一个递归函数_H
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int res = yep(root);
        if (res == -1) return false;
        return true;
    }

    int yep(TreeNode *node){
        if (!node) return 0;
        int left = yep(node->left);
        if (left == -1) return -1;
        int right = yep(node->right);
        if (right == -1) return -1;

        int res = abs(left - right);
        if (res > 1) return -1;
        else return (left > right) ? left + 1:right + 1;
    }

};
#endif //P7_P110_递归写法_一个递归函数_H
