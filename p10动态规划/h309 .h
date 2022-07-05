//
// Created by xm on 2022/7/5.
//

#ifndef P10_H309_H
#define P10_H309_H
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
#endif //P10_H309_H
