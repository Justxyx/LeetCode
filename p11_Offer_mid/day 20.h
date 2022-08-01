//
// Created by xm on 2022/8/1.
//

#ifndef P11_OFFER_MID_DAY_20_H
#define P11_OFFER_MID_DAY_20_H

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        TreeNode *node = new TreeNode(preorder[0]);
        if (preorder.size() == 1 && inorder.size() == 1)
            return node;
        vector<int>::iterator p = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int left = p - inorder.begin();
        vector<int> pre_left = vector<int>(preorder.begin()+1, preorder.begin()+1+left);
        vector<int> pre_right = vector<int>(preorder.begin()+1+left, preorder.end());
        vector<int> inor_left = vector<int>(inorder.begin(), inorder.begin() + left);
        vector<int> inor_right = vector<int>(inorder.begin()+left+1, inorder.end());
        node->left = buildTree(pre_left, inor_left);
        node->right = buildTree(pre_right, inor_right);
        return node;
    }
};

// 快速幂算法
class Solution2 {
public:
    double myPow(double x, int n) {
        int sum = 1;
        while (n > 0) {
            if (n /2 == 1) // 奇
                sum *= x;
            x *= x;
            n = n/2;
        }
        return sum;
    }
};

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty() || postorder.size() == 1)
            return true;

        int back = postorder.back();
        int i;
        for (i = 0; i < postorder.size(); ++i) {
            if (postorder[i] > back)
                break;
        }
        if (i == postorder.size())
            --i;
        vector<int> left = vector<int>(postorder.begin(), postorder.begin()+i);
        vector<int> right = vector<int>(postorder.begin()+i, postorder.end()-1);
        if ( !right.empty() && *min_element(right.begin(), right.end()) < back)
            return false;
        return verifyPostorder(left) * verifyPostorder(right);
    }

};

#endif //P11_OFFER_MID_DAY_20_H
