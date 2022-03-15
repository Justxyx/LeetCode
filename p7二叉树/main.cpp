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


class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int max = 0;
        if (root == nullptr) return 0;
        queue.push(root);
        TreeNode *temp;
        while (!queue.empty()){
            ++ max;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.front();
                queue.pop();
                if (temp->left == nullptr && temp->right == nullptr) return max;
                if (temp->right) queue.push(temp->right);
                if (temp->left) queue.push(temp->left);
            }
        }
        return max;
    }
};



int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    root.right = &node2;
    node2.left = &node3;
    vector<int> res;
    std::reverse(res.begin(), res.end());

    Solution solution;
    int i = solution.maxDepth(&root);
    cout << i << endl;
}