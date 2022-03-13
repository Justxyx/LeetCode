//
// Created by 肖应雄 on 2022/3/13.
//

#ifndef P7_P199_H
#define P7_P199_H
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        vector<int> bind;
        if (!root) return bind;
        TreeNode *temp;
        queue.push(root);
        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                if (i == size -1) bind.push_back(temp->val);
                queue.pop();
                if (temp->left != nullptr) queue.push(temp->left);
                if (temp->right != nullptr) queue.push(temp->right);
//                bind.push_back(temp->val);
            }
//            res.push_back(bind);
//            bind.clear();
        }
//        std::reverse(res.begin(), res.end());
        return bind;
    }
};

#endif //P7_P199_H
