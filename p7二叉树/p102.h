//
// Created by 肖应雄 on 2022/3/13.
//

#ifndef P7_P102_H
#define P7_P102_H
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        vector<int> bind;
        if (!root) return res;
        TreeNode *temp;
        queue.push(root);
        queue.push(nullptr);
        while (!queue.empty()){
            temp = queue.front();
            if (temp != nullptr){
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
                bind.push_back(temp->val);
                queue.pop();
            } else{
                res.push_back(bind);
                bind.clear();
                queue.pop();
                if (!queue.empty()) queue.push(nullptr);
            }
        }
        return res;
    }
};
#endif //P7_P102_H
