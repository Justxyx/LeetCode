//
// Created by 肖应雄 on 2022/3/12.
//

#ifndef P7_P94_迭代法的统一写法_H
#define P7_P94_迭代法的统一写法_H

/**
 *  迭代法 遍历的统一写法  中序遍历写法
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;

        TreeNode *temp;
        if (root == nullptr)
            return res;

        stack.push(root);
        while (!stack.empty()){
            temp = stack.top();
            if (temp != nullptr){
                stack.pop();
                if (temp->right)
                    stack.push(temp->right);
                stack.push(temp);
                stack.push(nullptr);
                if (temp->left) stack.push(temp->left);
            } else{
                stack.pop();
                temp = stack.top();
                res.push_back(temp->val);
                stack.pop();
            }
        }
        return res;
    }
};

#endif //P7_P94_迭代法的统一写法_H
