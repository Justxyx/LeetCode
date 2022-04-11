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




int main(){
    TreeNode node1(1);
    TreeNode node2(0);
    TreeNode node3(2);
    TreeNode node4(2);

    node1.right = &node3;

    Solution solution;
    vector<int> res = solution.findMode(&node1);
//    for (const auto &item : res)
//        cout << item << endl;




}