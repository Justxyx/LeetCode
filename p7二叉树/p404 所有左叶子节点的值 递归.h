//
// Created by 肖应雄 on 2022/3/26.
//

#ifndef P7_P404_所有左叶子节点的值_递归_H
#define P7_P404_所有左叶子节点的值_递归_H

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sums(root,sum);
        return sum;
    }

    void sums(TreeNode *node,int &sum){
        if (node == nullptr)
            return;
        if (node->left != nullptr){
            TreeNode *temp = node->left;
            if (temp->left == nullptr && temp->right == nullptr)
                sum += temp->val;
        }
        sums(node->left,sum);
        sums(node->right,sum);
    }

};
#endif //P7_P404_所有左叶子节点的值_递归_H
