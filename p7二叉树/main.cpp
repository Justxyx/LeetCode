#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };


class Solution1 {
public:
    int findBottomLeftValue(TreeNode* root) {

        int len = 0;
        multimap<int,int> map;
        dep(root,len,map);
        if (map.size() == 0)
            return root->val;

        auto begin = map.begin();
        auto end = map.end();
        int maxKey = begin->first;
        while (begin != end){
            if (begin->first > maxKey)
                maxKey = begin->first;
            ++ begin;
        }
        int count = map.count(maxKey);
        auto p = map.find(maxKey);
        int maxValue = p->second;
        for (int i = 0; i < count; ++i) {
            if (maxValue < p->second)
                maxValue = p->second;
            ++ p;
        }
        return maxValue;
    }

    void dep(TreeNode *node,int &len,multimap<int,int> &map){
        if (node == nullptr)
            return;
        ++ len;
        if (node->left != nullptr){
            if (node->left->left == nullptr && node->right->right == nullptr)
                map.insert({len,node->left->val});
        }
        dep(node->left,len,map);
        dep(node->right,len,map);
        --len;
        return;
    }
};





int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);

//    root.left = &node2;
    root.right = &node3;

    Solution solution;
    cout << solution.findBottomLeftValue(&root) << endl;


}