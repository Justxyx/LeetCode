//
// Created by 肖应雄 on 2022/4/12.
//

#ifndef P7_H236_递归_二叉树两个节点的祖先节点_H
#define P7_H236_递归_二叉树两个节点的祖先节点_H

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        if (left != nullptr && right != nullptr)
            return root;
        else if (left == nullptr && right != nullptr)
            return right;
        else if (left != nullptr && right == nullptr)
            return left;
        else
            return nullptr;
    }
};
#endif //P7_H236_递归_二叉树两个节点的祖先节点_H
