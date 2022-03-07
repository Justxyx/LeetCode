//
// Created by 肖应雄 on 2022/3/7.
//

#ifndef P7_P144迭代法_H
#define P7_P144迭代法_H
/*
 * 后序遍历
 *      左  右  中
 * 迭代法
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode *temp;
        while (stack.size() != 0){
            temp = stack.top();
            stack.pop();
            res.push_back(temp->val);
            if (temp->right != nullptr)
                stack.push(temp->right);
            if (temp->left != nullptr)
                stack.push(temp->left);
        }
        return res;
    }
};
#endif //P7_P144迭代法_H
