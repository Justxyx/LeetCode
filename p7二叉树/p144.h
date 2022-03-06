//
// Created by 肖应雄 on 2022/3/7.
//

#ifndef P7_P144_H
#define P7_P144_H
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        erg(root,res);
        return res;
    }

    void erg(TreeNode *node,vector<int> &vector){
        if (node == nullptr)
            return;
        vector.push_back(node->val);
        erg(node->left, vector);
        erg(node->right,vector);
    }
};
#endif //P7_P144_H
