//
// Created by 肖应雄 on 2022/5/24.
//

#ifndef P9_H714_H
#define P9_H714_H
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice){
                minPrice = prices[i];
                continue;
            }

            if (prices[i] > minPrice+fee){
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
                continue;
            }
        }
        return res;
    }
};
#endif //P9_H714_H
