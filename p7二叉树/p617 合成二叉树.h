//
// Created by 肖应雄 on 2022/4/5.
//

#ifndef P7_P617_合成二叉树_H
#define P7_P617_合成二叉树_H

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        if (root1 == nullptr || root2 == nullptr){
            if (root1 == nullptr)
                return root2;
            else
                return root1;
        }

        int val = root1->val + root2->val;
        root1->val = val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
};
#endif //P7_P617_合成二叉树_H
