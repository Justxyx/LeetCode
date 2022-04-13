//
// Created by 肖应雄 on 2022/4/13.
//

#ifndef P7_H235_搜索二叉树的公共父节点_非递归写法_H
#define P7_H235_搜索二叉树的公共父节点_非递归写法_H
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while ( (root->val > max(p->val,q->val)) || (root->val < min(p->val,q->val))){
            if (root->val > (max(p->val,q->val)))
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};
#endif //P7_H235_搜索二叉树的公共父节点_非递归写法_H
