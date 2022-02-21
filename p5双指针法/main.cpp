#include <iostream>
using namespace std;
#include <vector>
#include <list>


 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

int main() {
    ListNode head(1, nullptr);
    Solution solution;
    solution.removeNthFromEnd(&head,1);

    return 0;
}
