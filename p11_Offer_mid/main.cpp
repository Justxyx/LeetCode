#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <queue>
#include <numeric>
using namespace std;
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };



int main() {
    MedianFinder  m;
    m.addNum(-1);
    m.addNum(-2);
    cout << m.findMedian() << endl;
    m.addNum(-3);
    cout << m.findMedian() << endl;
}