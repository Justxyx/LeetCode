//
// Created by 肖应雄 on 2022/3/11.
//

#ifndef P7_P145后序遍历迭代法_H
#define P7_P145后序遍历迭代法_H
/**
 * 后续遍历与先序遍历有关
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        if (root == nullptr)
            return res;
        stack.push(root);
        TreeNode *temp;
        while (!stack.empty()){
            temp = stack.top();
            res.push_back(temp->val);
            stack.pop();
            if (temp->left != nullptr){
                stack.push(temp->left);
            }
            if (temp->right != nullptr){
                stack.push(temp->right);
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
#endif //P7_P145后序遍历迭代法_H
