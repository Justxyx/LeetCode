//
// Created by 肖应雄 on 2022/4/4.
//

#ifndef P7_P105_构造二叉树_先序与中序_H
#define P7_P105_构造二叉树_先序与中序_H

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        TreeNode *node = new TreeNode(preorder.front());

        auto p = std::find(inorder.begin(), inorder.end(), node->val);
        vector<int> inLeft = vector<int>(inorder.begin(),p);
        vector<int> inRight = vector<int>(++p,inorder.end());

        vector<int> preLeft = vector<int>(++preorder.begin(),++preorder.begin() + inLeft.size());
        vector<int> preRight = vector<int>(++preorder.begin() + preLeft.size(),preorder.end());

        node->left = buildTree(preLeft,inLeft);
        node->right = buildTree(preRight,inRight);

        return node;

    }
};
#endif //P7_P105_构造二叉树_先序与中序_H
