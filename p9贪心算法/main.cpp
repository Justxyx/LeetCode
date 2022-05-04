#include <iostream>
using namespace std;
#include <vector>




int main() {
    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,7,8};
    Solution solution;
    cout <<  solution.findContentChildren(g,s);
}
