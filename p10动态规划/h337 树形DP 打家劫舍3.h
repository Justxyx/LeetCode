//
// Created by xm on 2022/6/27.
//

#ifndef P10_H337_树形DP_打家劫舍3_H
#define P10_H337_树形DP_打家劫舍3_H

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int> result = rb(root);
        return max(result.first,result.second);
    }
    pair<int,int> rb(TreeNode *node) {
        // first 取  second 不取
        if (node == nullptr)
            return {0,0};
        pair<int,int> left = rb(node->left);
        pair<int,int> right = rb(node->right);

        return {node->val + left.second + right.second , max(left.first,left.second) + max(right.first, right.second)};
    }
};
#endif //P10_H337_树形DP_打家劫舍3_H
