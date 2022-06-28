//
// Created by xm on 2022/6/28.
//

#ifndef P10_P121_买卖股票1_H
#define P10_P121_买卖股票1_H

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int sum = 0;
        for (const auto &item : prices) {
            if (item < min) {
                min = item;
                continue;
            } else {
                if (sum < (item-min))
                    sum = item - min;
            }
        }
        return sum;
    }
};
#endif //P10_P121_买卖股票1_H
