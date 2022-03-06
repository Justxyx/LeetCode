//
// Created by 肖应雄 on 2022/3/7.
//

#ifndef P7_P94_H
#define P7_P94_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        erg(root,res);
    }

    void erg(TreeNode *node,vector<int> &vector){
        if (node == nullptr)
            return;
        erg(node->left, vector);
        vector.push_back(node->val);
        erg(node->right,vector);
    }
};

#endif //P7_P94_H
