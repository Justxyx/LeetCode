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
    TreeNode node(1);
    node.left = new TreeNode(2);
    node.right = new TreeNode(2);

    TreeNode res(3);
    Solution solution;
    cout << solution.isSymmetric(&node);
}