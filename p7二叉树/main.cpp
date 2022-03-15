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


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> queue;
        Node *pre,*next;
        queue.push(root);

        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                if (i == 0){
                    pre = queue.front();
                    pre->next = nullptr;
                    queue.pop();
                    if (pre->right) queue.push(pre->right);
                    if (pre->left) queue.push(pre->left);
                    continue;
                }
                next = queue.front();
                queue.pop();
                if (next->right) queue.push(next->right);
                if (next->left) queue.push(next->left);
                pre->next = next;
                next->next = nullptr;
                pre = next;
            }
        }
        return root;
    }
};













#include <unistd.h>
#include <netdb.h>

int main(){
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    root.right = &node2;
    node2.left = &node3;
    vector<int> res;
    std::reverse(res.begin(), res.end());

    struct hostent *hp;
    char hostname[1024];
    gethostname(hostname,1024);
    hp = gethostbyname(hostname);

//    cout << hp->h_addr_list[0] << endl;

    uint16_t s =   htons(12);
    cout << s << endl;
}