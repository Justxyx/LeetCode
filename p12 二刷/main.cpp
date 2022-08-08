#include <iostream>
#include <vector>
using namespace std;
#include <numeric>
#include <set>
#include <list>

class Solution509 {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int f0 = 0, f1 = 1;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = f0 + f1;
            f0 = f1;
            f1 = res;
        }
        return res;
    }
};

class Solution70 {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }
};

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 3)
            return min(cost[0], cost[1]);
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp.back(), dp[dp.size()-2]);
    }
};

int main() {

}
