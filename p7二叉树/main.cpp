#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include<numeric>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
/**
 * 节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
 */

/*
 *              5
 *            4   6
 *              3   7
 */


int main(){
    TreeNode root(1);
    TreeNode node2(2);


    TreeNode node3(3);

    root.right = &node3;
    node3.left = &node2;

    Solution solution;
    cout << solution.getMinimumDifference(&root);



}