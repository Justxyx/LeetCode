//
// Created by 肖应雄 on 2022/4/2.
//

#ifndef P7_P106_构造二叉树_后序中序_H
#define P7_P106_构造二叉树_后序中序_H

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()){
            return nullptr;
        }

        if (inorder.size() == 1){
            TreeNode *node = new TreeNode(inorder.front());
            return node;
        }

        auto p = postorder.end();
        --p;
        TreeNode *node = new TreeNode(*p);

        auto p2 = std::find(inorder.begin(), inorder.end(), *p);

        vector<int> in_left(inorder.begin(),p2);
        vector<int> in_right(++p2,inorder.end());

        vector<int> po_left(postorder.begin(),postorder.begin() + in_left.size());
        vector<int> po_right(postorder.begin()+in_left.size(),--postorder.end());
        node->left = buildTree(in_left,po_left);
        node->right = buildTree(in_right,po_right);
        return node;
    }
};

#endif //P7_P106_构造二叉树_后序中序_H
