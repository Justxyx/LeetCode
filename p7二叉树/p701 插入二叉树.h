//
// Created by 肖应雄 on 2022/4/14.
//

#ifndef P7_P701_插入二叉树_H
#define P7_P701_插入二叉树_H
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            return new TreeNode(val);
        }
        TreeNode *node = root;
        TreeNode *pre = nullptr;
        while (node != nullptr){
            pre = node;
            if (node->val > val)
                node = node->left;
            else
                node = node->right;
        }

        if (pre->val > val)
            pre->left = new TreeNode(val);
        else
            pre->right = new TreeNode(val);

        return root;
    }
};
#endif //P7_P701_插入二叉树_H
