#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };


 /**
        if(subRoot == nullptr || isSameTree(root,subRoot)) return true;
        if(root == nullptr && subRoot!=nullptr) return false;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

  */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        bool b = isSameTree(root,subRoot);
        if (b) return true;

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





int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    root.right = &node2;
    node2.left = &node3;

    Solution solution;
    cout << solution.isBalanced(&root);




}