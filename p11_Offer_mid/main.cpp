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
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abc");
}
/*
 * 12258
 * b c c
 * b w
 * f b
 */