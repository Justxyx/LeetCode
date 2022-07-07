#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode *temp = head;
        int count = 1;
        while (temp->next != nullptr) {
            ++ count;
            temp = temp->next;
        }
        vector<int> v(count,0);
        while (head->next != nullptr) {
            v[--count] = head->val;
            head = head->next;
        }
        return v;
    }
};
int main() {

}