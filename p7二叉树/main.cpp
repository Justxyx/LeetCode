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
     vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> res;
            vector<string> vec;
         solut(root,res,vec);
         return res;
     }

     void solut(TreeNode *node,vector<string> &res,vector<string> &vec){


         if (node->left == nullptr && node->right == nullptr){
             vec.pop_back();
             string s = "";
             for (const auto &item : vec)
                 s += item;
             res.push_back(s);
         }




         if (node->left != nullptr){
             solut(node->left,res,vec);
            vec.pop_back();
         }
         if (node->right != nullptr)
         {
             solut(node->right,res,vec);
             vec.pop_back();

         }


     }
 };






int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    root.right = &node2;
    node2.left = &node3;

    Solution solution;
    solution.binaryTreePaths(&root);




}