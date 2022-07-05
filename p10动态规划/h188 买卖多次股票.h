//
// Created by xm on 2022/7/5.
//

#ifndef P10_H188_买卖多次股票_H
#define P10_H188_买卖多次股票_H

class Solution {
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

#endif //P10_H188_买卖多次股票_H
