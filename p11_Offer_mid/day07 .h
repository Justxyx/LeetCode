//
// Created by xm on 2022/7/16.
//

#ifndef P11_OFFER_MID_DAY07_H
#define P11_OFFER_MID_DAY07_H
class Solution1 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return track(A, B);
    }
    // 以A遍历
    bool track(TreeNode *p1, TreeNode *p2) {
        if (p1 == nullptr)
            return false;
        bool b1 = tracking(p1,p2);
        bool b2 = track(p1->left,p2);
        bool b3 = track(p1->right, p2);
        return b1 || b2 || b3;
    }
    bool tracking(TreeNode *n1, TreeNode *n2) {
        if (n2 == nullptr)
            return true;
        if (n1 == nullptr)
            return false;
        if (n1->val != n2->val)
            return false;

        return  tracking(n1->left, n2->left) * tracking(n1->right, n2->right);
    }
};

class Solution2 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        back(root);
        return root;
    }
    void back(TreeNode *node) {
        if (node == nullptr)
            return;
        back(node->left);
        back(node->right);
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        return;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return track(root->left, root->right);
    }
    bool track(TreeNode *p1, TreeNode *p2) {
        if (p1 == nullptr && p2 == nullptr)
            return true;
        if (p1 == nullptr || p2 == nullptr)
            return false;
        if (p1->val != p2->val)
            return false;
        return track(p1->left, p2->right) * track(p1->right, p2->left);
    }
};

#endif //P11_OFFER_MID_DAY07_H
