//
// Created by xm on 2022/7/14.
//

#ifndef P11_OFFER_MID_DAY_06_H
#define P11_OFFER_MID_DAY_06_H

class Solution1 {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            auto p = que.front();
            res.push_back(p->val);
            if (p->left != nullptr)
                que.push(p->left);
            if (p->right != nullptr)
                que.push(p->right);
            que.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        vector<int> bind;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p != nullptr) {
                bind.push_back(p->val);
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
            } else {
                res.push_back(bind);
                bind.clear();
                if (que.empty())
                    break;

                que.push(nullptr);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        vector<int> bind;
        int count = 0;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p != nullptr) {
                bind.push_back(p->val);
                if (p->left != nullptr)
                    que.push(p->left);
                if (p->right != nullptr)
                    que.push(p->right);
            } else {
                if (count % 2 == 1)
                    reverse(bind.begin(), bind.end());
                res.push_back(bind);
                bind.clear();
                if (que.empty())
                    break;

                que.push(nullptr);
                ++ count;
            }
        }
        return res;
    }
};

#endif //P11_OFFER_MID_DAY_06_H
