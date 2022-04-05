//
// Created by 肖应雄 on 2022/4/5.
//

#ifndef P7_P654_递归构造最大二叉树_H
#define P7_P654_递归构造最大二叉树_H

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        int max = findMax(nums);
        TreeNode *node = new TreeNode(max);
        auto p = std::find(nums.begin(), nums.end(), max);
        vector<int> left = vector<int>(nums.begin(),p);
        vector<int> right = vector<int>(++p,nums.end());
        node->left = constructMaximumBinaryTree(left);
        node->right = constructMaximumBinaryTree(right);
        return node;
    }

    int findMax(vector<int> &nums){
        int max = nums.front();
        for (const auto &item : nums){
            if (item > max)
                max = item;
        }
        return max;
    }
};

#endif //P7_P654_递归构造最大二叉树_H
