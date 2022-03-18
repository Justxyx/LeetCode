//
// Created by 肖应雄 on 2022/3/18.
//

#ifndef P7_P222_递归_节点个数_H
#define P7_P222_递归_节点个数_H

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

#endif //P7_P222_递归_节点个数_H
