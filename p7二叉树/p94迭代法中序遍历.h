//
// Created by 肖应雄 on 2022/3/10.
//

#ifndef P7_P94迭代法中序遍历_H
#define P7_P94迭代法中序遍历_H
/**
 * 中序遍历 迭代法
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        if (root == nullptr)
            return res;
        TreeNode *temp;
        temp = root;

        while (temp != nullptr || !stack.empty() ){
            if (temp != nullptr){
                stack.push(temp);
                temp = temp->left;
            } else{
                temp = stack.top();
                res.push_back(temp->val);
                temp = temp->right;
                stack.pop();
            }
        }
        return res;
    }
};
#endif //P7_P94迭代法中序遍历_H
