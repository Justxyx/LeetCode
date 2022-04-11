#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include<numeric>
#include <unordered_map>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };


class Solution {
public:
    pair<TreeNode*,int> pair;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = 0;
        find(root,p,p,l);
        return pair.first;
    }

    void find(TreeNode *root,TreeNode *p1,TreeNode *p2,int &l){
        if (root == nullptr){
            return;
        }

        ++l;
        find(root->left,p1,p2,l);
        find(root->right,p1,p2,l);

        bool b = findNode(root,p1) * findNode(root,p2);
        if (b){
            if (pair.second > l){
                pair.first = root;
                pair.second = l;
            }
        }
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



int main(){
    TreeNode node1(1);
    TreeNode node2(0);
    TreeNode node3(2);
    TreeNode node4(2);

    node1.right = &node3;

    Solution solution;
    cout << solution.findNode(&node3,&node4);


}