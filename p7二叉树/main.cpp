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

int main(){
    TreeNode root(1);
    TreeNode node2(2);

    vector<int> in{9,3,15,20,7};
    vector<int> po{9,15,7,20,3};

    Solution solution;
    TreeNode *node =  solution.buildTree(in,po);

    cout << node->val << endl;



}