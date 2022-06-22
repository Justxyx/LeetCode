#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>

class Solution {
public:
    static bool comp(int a, int b) {
        return a > b;
    }
    int coinChange(vector<int>& coins, int amount) {
        if (*min_element(coins.begin(), coins.end()) > amount)
            return -1;
        std::sort(coins.begin(), coins.end(), comp);
        vector<int> res(amount+1, 0);
        res[0] = 1;
        for (const auto &item : coins) {
            for (int i = 1; i < res.size(); ++i) {
                if ( (i-item >= 0) && (res[i-item] != 0)) {
                    int min = 0;
                    if (i-item == 0)
                        min = 1;
                    else
                        min = res[i-item] + 1;
                    if (res[i] == 0)
                        res[i] = min;
                    else if (res[i] > min)
                        res[i] = min;
                }
            }
            int i = 3;
        }
        return res.back() == 0 ? -1:res.back();
    }
};

int main() {
    vector<int> v{1,2,5};
    Solution solution;
    cout << solution.coinChange(v,11);
    return 0;
}

