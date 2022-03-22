//
// Created by 肖应雄 on 2022/3/22.
//

#ifndef P7_P110_平衡二叉树_递归_H
#define P7_P110_平衡二叉树_递归_H
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (isTrue(root) == -1) return false;
        return true;
    }

    int isTrue(TreeNode *node){
        if (!node) return 0;

        int left = isTrue(node->left);
        if (left == -1) return left;
        int right = isTrue(node->right);
        if (right == -1) return right;
        if (right == 2){
            cout << right <<endl;
        }
        if (abs(left - right) > 1) return -1;
        return max(left,right) + 1;
    }
};
#endif //P7_P110_平衡二叉树_递归_H
