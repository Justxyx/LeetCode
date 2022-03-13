//
// Created by 肖应雄 on 2022/3/13.
//

#ifndef P7_P637_H
#define P7_P637_H
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> queue;
        vector<int> bind;

        if (!root) return res;
        queue.push(root);
        TreeNode *temp;
        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
                queue.pop();
                bind.push_back(temp->val);
            }
            double result = average(bind);
            bind.clear();
            res.push_back(result);
        }
        return res;
    }

    double average(vector<int> bind){
        double sum = 0;
        for (const auto &item : bind){
            sum += item;
        }
        return sum/bind.size();
    }
};
#endif //P7_P637_H
