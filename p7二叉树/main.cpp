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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *preNode = nullptr;
        TreeNode *node = root;
        TreeNode *nextNode = nullptr;

        while (node != nullptr && node->val != key){
            preNode = node;
            if (node->val > key)
                node = node->left;
            else
                node = node->right;
        }

        if (node == nullptr)
            return root;

        //1. node为叶子节点
        if (node->left == nullptr && node->right == nullptr){
            delete node;
        }

        // 2. 如果node有单子节点
        else if (node->left == nullptr || node->right == nullptr){
            if (node->left == nullptr){
                preNode = node->right;
                delete node;
            } else{
                preNode = node->left;
                delete node;
            }
        }

        // 3. node有两个节点
        else{


        }



        return root;
    }
};


int main(){
    TreeNode node1(1);
    TreeNode node2(0);
    TreeNode node3(2);
    TreeNode node4(2);

    node1.right = &node3;




}