//
// Created by 肖应雄 on 2022/4/13.
//

#ifndef P7_H235_搜索二叉树的公共祖先_H
#define P7_H235_搜索二叉树的公共祖先_H


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        if (left != nullptr && right != nullptr)
            return root;
        else if (left != nullptr)
            return left;
        else if (right != nullptr)
            return right;
        else return nullptr;
    }
};
#endif //P7_H235_搜索二叉树的公共祖先_H
