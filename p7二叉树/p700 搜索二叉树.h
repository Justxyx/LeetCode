//
// Created by 肖应雄 on 2022/4/6.
//

#ifndef P7_P700_搜索二叉树_H
#define P7_P700_搜索二叉树_H
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        if (root->val == val)
            return root;

        TreeNode *left = searchBST(root->left,val);
        TreeNode *right = searchBST(root->right,val);

        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;

        return nullptr;


    }
};
#endif //P7_P700_搜索二叉树_H
