#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <queue>
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };



int main() {
    TreeNode node(12);
    node.left = new TreeNode(13);
    Solution solution;
    solution.levelOrder(&node);
}