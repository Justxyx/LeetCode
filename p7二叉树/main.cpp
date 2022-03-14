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