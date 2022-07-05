//
// Created by xm on 2022/7/5.
//

#ifndef P10_P714_DP_股票_带费用问题_H
#define P10_P714_DP_股票_带费用问题_H

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int has = -prices[0] - fee;
        int no_has = 0;


        for (int i = 1; i < prices.size(); ++i) {
            has = max(has, no_has -prices[i]-fee);
            no_has = max(no_has, prices[i] + has);
        }
        return no_has;
    }
};
#endif //P10_P714_DP_股票_带费用问题_H
