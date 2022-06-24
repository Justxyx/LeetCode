#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cmath>



int main() {
    string str = "leetcode";
    vector<string> v{"leet", "code"};
    Solution solution;
    cout << solution.wordBreak(str,v);
    return 0;
}

