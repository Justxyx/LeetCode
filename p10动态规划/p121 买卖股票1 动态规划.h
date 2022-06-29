//
// Created by xm on 2022/6/29.
//

#ifndef P10_P121_买卖股票1_动态规划_H
#define P10_P121_买卖股票1_动态规划_H
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int has = INT_MAX;
        int no_has = INT_MIN;
        for (const auto &item : prices) {


            if (has > item)
                has = item;

            no_has = max(no_has, item - has);
        }
        return no_has < 0 ? 0 : no_has;
    }
};
#endif //P10_P121_买卖股票1_动态规划_H
