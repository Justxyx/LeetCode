//
// Created by 肖应雄 on 2022/3/7.
//

#ifndef P7_P145_H
#define P7_P145_H

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        erg(root,res);
        return res;
    }

    void erg(TreeNode *node,vector<int> &vector){
        if (node == nullptr)
            return;
        erg(node->left, vector);
        erg(node->right,vector);
        vector.push_back(node->val);
    }
};
#endif //P7_P145_H
