//
// Created by xm on 2022/7/31.
//

#ifndef P11_OFFER_MID_DAY_19_H
#define P11_OFFER_MID_DAY_19_H

class Solution1 {
public:
    int sumNums(int n) {
        if (n <= 0)
            return 0;
        return n + sumNums(n-1);
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = min(p->val, q->val);
        int right = max(p->val, q->val);
        while (!(root->val >= left && root->val <= right)) {
            if (root->val > right)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};
class Solution {
public:
    TreeNode *res;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        findNode(root, p, q);
        return res;
    }

    bool findNode(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;

        cout << root->val << "," ;

        bool left = findNode(root->left, p, q);
        bool right =  findNode(root->right, p, q);
        // cout << "root:" << root->val << "; left = " << left << " ; right = " << right << endl;
        if (left&&right)
            res = root;

        if ((root->val == p->val || root->val == q->val) && (left || right))
            res = root;

        if (root->val == p->val || root->val == q->val)
            return true;

        return left || right;
    }

};
#endif //P11_OFFER_MID_DAY_19_H
