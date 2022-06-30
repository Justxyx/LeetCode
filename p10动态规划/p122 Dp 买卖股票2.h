//
// Created by xm on 2022/6/30.
//

#ifndef P10_P122_DP_买卖股票2_H
#define P10_P122_DP_买卖股票2_H

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int no_has = 0;  // 未持有股票 手里的现金
        int has = -prices[0];    // 持有股票 手里的现金

        for (int i = 1; i < prices.size(); ++i) {
            // 持有股票
            int temp_has = has;
            has = max(has,no_has-prices[i]);
            // 不持有
            no_has = max(no_has,temp_has+prices[i]);
        }
        return no_has;
    }
};
#endif //P10_P122_DP_买卖股票2_H
