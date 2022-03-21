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



int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    root.right = &node2;
    node2.left = &node3;


    cout << abs(3 - 5);

}