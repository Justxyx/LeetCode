//
// Created by xm on 2022/7/5.
//

#ifndef P10_H188_买卖两次股票_H
#define P10_H188_买卖两次股票_H

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

#endif //P10_H188_买卖两次股票_H
