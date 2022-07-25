//
// Created by xm on 2022/7/25.
//

#ifndef P11_OFFER_MID_DAY_15_H
#define P11_OFFER_MID_DAY_15_H

class Solution34 {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return res;
        backtracking(root, target);
        return res;
    }

    void backtracking(TreeNode *node, int target) {
        path.push_back(node->val);
        int sum = accumulate(path.begin(), path.end(), 0);
        if (node->left == nullptr && node->right == nullptr && sum == target) {
            res.push_back(path);
        }
//        if (abs(sum) > abs(target))
//            return;
        if (node->left != nullptr) {
            backtracking(node->left, target);
            path.pop_back();
        }
        if (node->right != nullptr) {
            backtracking(node->right, target);
            path.pop_back();
        }
        return;
    }
};

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution36 {
public:
    Node *temp;
    Node *head;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        temp = nullptr;
        backtracking(root);
        temp->right = head;
        head->left = temp;
        return head;
    }

    void backtracking(Node *node) {
        if (node == nullptr)
            return;
        backtracking(node->left);
        if (temp == nullptr) {
            head = node;
            temp = head;
        } else {
            temp->right = node;
            node->left = temp;
            temp = node;
        }
        backtracking(node->right);
    }
};

class Solution54 {
public:
    int count = 0;
    int res = 0;
    int kthLargest(TreeNode* root, int k) {
        backtracking(root, k);
        return res;
    }

    void backtracking(TreeNode *node, int k){
        if (node == nullptr)
            return;
        backtracking(node->left);
        ++ count;
        if (count == k)
            res = node->val;
        backtracking(node->right);
        return;
    }
};
#endif //P11_OFFER_MID_DAY_15_H
