//
// Created by 肖应雄 on 2022/5/8.
//

#ifndef P9_P122_股票买卖问题_H
#define P9_P122_股票买卖问题_H

/*
 * 不管递减 只管递增
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
//        int pre = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            // 递减序列
            if (prices[i] < prices[i-1]){
//                pre = prices[i];
                continue;
            }
            else{
//                sum += (prices[i-1] - pre);
//                pre = prices[i];
                sum += (prices[i] - prices[i-1]);
            }
        }
        return sum;
    }
};
#endif //P9_P122_股票买卖问题_H
