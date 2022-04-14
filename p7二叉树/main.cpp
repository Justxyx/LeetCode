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
    TreeNode *cur = nullptr;
    TreeNode *nextNode = nullptr;
    TreeNode *preCur = nullptr;

    bool isFind = false;
    TreeNode* deleteNode(TreeNode* root, int key) {
        findNode(root,key);
        if (cur == nullptr)
            return root;


        // 1. cur 为叶子节点
        if (cur->left == nullptr && cur->right == nullptr){
            delete cur;
        } else if (cur->left == nullptr || cur->right != nullptr){
            if (preCur->right == cur){
                if (cur->left == nullptr)
                    preCur->right = cur->right;
                else
                    preCur->right = cur->left;
            } else{
                if (cur->right == nullptr)
                    preCur->left = cur->left;
                else
                    preCur->left = cur->right;
            }
        } else{
            cur->val = nextNode->val;
            if (nextNode->left == nullptr && nextNode->right == nullptr)
                delete nextNode;
            else{
                if (cur->left == nextNode){
                    if (nextNode->left != nullptr)
                        cur->left = nextNode->left;
                    else
                        cur->left = nextNode->right;
                } else{
                    if (nextNode->left != nullptr)
                        cur->right = nextNode->left;
                    else
                        cur->right = nextNode->right;
                }
            }

        }
        return root;
    }

    TreeNode* findNode(TreeNode *node,int key){
        if (node == nullptr)
            return nullptr;


        TreeNode *left = findNode(node->left, key);
        if (left != nullptr)
            return left;


        /*
         * 中节点处理逻辑
         */
        if (isFind){
            nextNode = node;
        }
        if (node->val == key){
            cur = node;
        } else{
            preCur = node;
        }


        TreeNode *right = findNode(node->right,key);
        if (right != nullptr)
            return right;
        return nullptr;
    }
};



int main(){
    TreeNode node1(1);
    TreeNode node2(0);
    TreeNode node3(2);
    TreeNode node4(2);

    node1.right = &node3;




}