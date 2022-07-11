#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> bind(26,0);
        for (const auto &item : s) {
            ++ bind[item - 97];
        }
        for (const auto &item : s) {
            if (bind[item-97] == 1)
                return item;
        }
        return ' ';
    }
};


int main() {

    Solution solution;
    cout <<(int) 'a' << endl;
}