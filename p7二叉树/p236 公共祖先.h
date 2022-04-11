//
// Created by 肖应雄 on 2022/4/11.
//

#ifndef P7_P236_公共祖先_H
#define P7_P236_公共祖先_H
class Solution {
public:
    pair<TreeNode*,int> pair;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = 0;
        find(root,p,q,l);
        return pair.first;
    }

    void find(TreeNode *root,TreeNode *p1,TreeNode *p2,int &l){
        if (root == nullptr){
            return;
        }


        ++l;

        bool b = findNode(root,p1)* findNode(root,p2);
        if (b){
            cout << root->val << ":" << l << endl;
            if (pair.second < l){
                pair.first = root;
                pair.second = l;
            }
        }

        find(root->left,p1,p2,l);
        find(root->right,p1,p2,l);

        return;
    }

    bool findNode(TreeNode *node,TreeNode *p){
        if (node == nullptr)
            return false;

        if (node->val == p->val)
            return true;


        return findNode(node->left,p) || findNode(node->right,p);
    }
};
#endif //P7_P236_公共祖先_H
