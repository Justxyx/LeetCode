//
// Created by 肖应雄 on 2022/3/22.
//

#ifndef P7_P100_两棵相同的树吗_H
#define P7_P100_两棵相同的树吗_H

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;
        else if (p->val != q->val) return false;

        bool booLeft = isSameTree(p->left,q->left);
        bool boolRight = isSameTree(p->right,q->right);
        return booLeft*boolRight;
    }
};

#endif //P7_P100_两棵相同的树吗_H
