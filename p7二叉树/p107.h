//
// Created by 肖应雄 on 2022/3/13.
//

#ifndef P7_P107_H
#define P7_P107_H
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        std::reverse(res.begin(), res.end());
        return res;
    }
};



#endif //P7_P107_H
