#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>




int main() {
    Node *node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    Solution solution;
    Node* n = solution.copyRandomList(node);
    while (n) {
        cout << n->val << endl;
        n = n->next;
    }
}