//
// Created by 肖应雄 on 2022/3/30.
//


class Solution {
public:
    vector<int> vec;
    vector<vector<int>> res;
    int sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        sum = targetSum;
        find(root);
        return res;
    }
    void find(TreeNode *node){
        vec.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr){
            if (accumulate(vec.begin(),vec.end(),0) == sum){
                res.push_back(vec);
            }
            return;
        }

        if (node->left != nullptr){
            find(node->left);
            vec.erase(--vec.end());
        }
        if (node->right != nullptr){
            find(node->right);
            vec.erase(--vec.end());
        }
        return;
    }
};