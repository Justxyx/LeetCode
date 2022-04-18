#include <iostream>
using namespace std;
#include <vector>
#include <numeric>


class Solution {
public:
    vector<pair<int,int>> path;
    vector<string> letterCombinations(string digits) {
        vector<int> digit;
        for (const auto &item : digits)
            digit.push_back(item - '0');

    }

    void trackbacking(vector<int> digit,int index){

    }
};


int main() {
    Solution solution;
    solution.letterCombinations("123");
    return 0;
}
