//
// Created by 肖应雄 on 2022/3/29.
//

#ifndef P7_P112_路径总和_H
#define P7_P112_路径总和_H
class Solution {
public:
    int sum = 0;
    int target = 0;
    bool b = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        target = targetSum;
        sum = root->val;
        find(root);
        return b;
    }

    void find(TreeNode *node){
        if (node->left == nullptr && node->right == nullptr){
            if (sum == target)
                b = true;
            return;
        }

        if (node->left){
            sum += node->left->val;
            find(node->left);
            sum -= node->left->val;
        }
        if (node->right){
            sum += node->right->val;
            find(node->right);
            sum -= node->right->val;
        }
        return;
    }
};

#endif //P7_P112_路径总和_H
