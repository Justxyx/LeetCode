//
// Created by 肖应雄 on 2022/3/23.
//

#ifndef P7_H572_一棵树是否是另外一棵树子树_递归_H
#define P7_H572_一棵树是否是另外一棵树子树_递归_H

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        bool b = isSameTree(root,subRoot);
        if (b) return true;
        if (!root) return false;

        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return left || right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;
        else if (p->val != q->val) return false;

        bool booLeft = isSameTree(p->left,q->left);
        bool boolRight = isSameTree(p->right,q->right);
        return booLeft*boolRight;
    }
};
#endif //P7_H572_一棵树是否是另外一棵树子树_递归_H
