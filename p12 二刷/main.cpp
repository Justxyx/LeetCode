#include <iostream>
#include <vector>
using namespace std;
#include <numeric>
#include <set>
#include <list>

/*
 * 第一周
 */
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

/*
 * 第二周
 */
class Solution62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = INT_MIN;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] != INT_MIN)
                obstacleGrid[i][0] = 1;
            else
                break;
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] != INT_MIN)
                obstacleGrid[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int a, b;
                if (obstacleGrid[i][j] == INT_MIN)
                    continue;
                obstacleGrid[i][j-1] == INT_MIN ? a = 0 : a = obstacleGrid[i][j-1];
                obstacleGrid[i-1][j] == INT_MIN ? b = 0 : b = obstacleGrid[i-1][j];
                obstacleGrid[i][j] = a + b;
            }
        }
        if (obstacleGrid.back().back() == INT_MIN)
            return 0;
        return obstacleGrid.back().back();
    }
};

class Solution343 {
public:
    int integerBreak(int n) {
        if (n < 3)
            return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            int maxs = 0;
            for (int j = 1; j < i; ++j) {
                maxs = max(max(maxs, j * (i-j)), (i-j) * dp[j]);
            }
            dp[i] = maxs;
        }
        return dp.back();
    }
};

class Solution {
public:
    /*
     * f1 =1;
     * f2 = 2;
     * f3 = 5;
     */
    int numTrees(int n) {
        if (n < 3)
            return n;
        vector<int> dp(n+1, 1);
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            // left
            int sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += dp[j] * dp[i-j-1];
//                cout << j << ":" <<  i-j-1<< endl;
            }
            dp[i] = sum;
        }
        return dp.back();
    }
};



/*
 * 第三周
 */
class Solution494 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
         *  正   a    负    b
         *  a - b = target;
         *  a+b = sum(nums);
         *  2a = target + sum;
         */
        if (nums.empty())
            return 0;

        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums < abs(target))
            return 0;
        if ((target + sums) % 2 == 1)
            return 0;
        int temp = (target + sums)/2;
        vector<int> dp(temp+1, 0);
        dp[0] = 1;
        for (const auto &item : nums) {
            for (int i = dp.size()-1; i >=0; --i) {
                if (i - item >= 0 && dp[i-item] != 0) {
                    dp[i] = dp[i-item] + dp[i];
//                    cout << i - item << endl;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    Solution solution;
    solution.numTrees(4);
}
