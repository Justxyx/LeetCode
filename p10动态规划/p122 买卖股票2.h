//
// Created by xm on 2022/6/28.
//

#ifndef P10_P122_买卖股票2_H
#define P10_P122_买卖股票2_H


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int sum = 0;
        for (int i = 0; i < prices.size()-1; ++i) {
            if (prices[i] > prices[i+1])
                continue;
            else
                sum += (prices[i+1] - prices[i]);
        }
        return sum;
    }
};
#endif //P10_P122_买卖股票2_H
