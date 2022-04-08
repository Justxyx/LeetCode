//
// Created by 肖应雄 on 2022/4/8.
//

#ifndef P7_H530_二叉树最小差值_递归_前节点_H
#define P7_H530_二叉树最小差值_递归_前节点_H
class Solution {
public:
    int mins = INT_MAX;
    TreeNode *preNode;
    int getMinimumDifference(TreeNode* root) {
        findMin(root);
        return mins;

    }

    void findMin(TreeNode *node){
        if (node == nullptr)
            return;
        findMin(node->left);
        // 中序处理
        if (preNode != nullptr){
            mins =min( mins,abs(preNode->val - node->val));
        }
        preNode = node;
        findMin(node->right);
    }
};
#endif //P7_H530_二叉树最小差值_递归_前节点_H
