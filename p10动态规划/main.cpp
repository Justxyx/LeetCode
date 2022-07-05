#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cmath>




/*
 *      dp[i][k][0]  第i天， 交易了k次， 手中没有股票
 *      dp[i][k][1]         交易了k次， 手中有股票
 *
 */

// 之买卖一次股票
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2,0)));
        dp[0][0][0] = 0;  // 第0天， 已经交易了0次 手中没有股票 那就等于0
        dp[0][1][1] = -prices[0];  // 第0天 已经交易了1 次 手中有股票
        for (int i = 0; i < prices.size(); ++i) {
            dp[i][0][0] = 0;
        }


        for (int i = 1; i < prices.size(); ++i) {
            // 第i天不持有
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);

            // 第i天持有
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]);
        }

        return dp[prices.size()-1][1][0];
    }
};

// 可买卖两次股票
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2,0)));
        for (int i = 0; i < prices.size(); ++i) {
            dp[i][0][0] = 0;   // 第i天， 发生了0次交易 手中没有股票  值为0
        }

        dp[0][1][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][2][1] = -prices[0];
        dp[0][2][0] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // 发生了一次交易
            // 不持有
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
            // 持有
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]);

            // 发生了两次交易
            // 不持有
            dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i]);
            // 持有
            dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i]);
        }
        return max(dp[prices.size()-1][1][0], dp[prices.size()-1][2][0]);
    }
};


class Solution3 {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2,0)));
        for (int i = 0; i < prices.size(); ++i) {
            dp[i][0][0] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            dp[0][i][1] = -prices[0];
            dp[0][i][0] = 0;
        }

        int maxx = 0;
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                // 不持有
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                // 持有
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                maxx = max(dp[i][j][0], dp[i][j][1]);
            }
        }
        return maxx;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4,0));
        /*
         *    0 -> 买入状态
         *    1 -> 卖出状态、   前两天就卖出了 度过了冷冻期
         *    2 -> 卖出状态     今天卖出
         *    3 -> 卖出状态     昨天卖出 今天冷冻期
         */

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // 0
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]) );

            // 1
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);

            // 2
            dp[i][2] = dp[i-1][0] + prices[i];

            // 3
            dp[i][3] = dp[i-1][2];
        }

        return max(dp.back()[1], max(dp.back()[2], dp.back()[3]) );
    }
};


int main() {

//    string s1 = "hello";
//    string s2 = "jay";
//    s1.swap(s2);
//    cout << s1 << s2 << endl;
    Solution solution;
    vector<int> v{1};
    cout << solution.maxProfit(v);
    return 0;
}

