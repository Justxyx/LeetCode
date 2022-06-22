//
// Created by xm on 2022/6/22.
//

#ifndef P10_P322_找零问题_H
#define P10_P322_找零问题_H
class Solution {
public:
    static bool comp(int a, int b) {
        return a > b;
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        std::sort(coins.begin(), coins.end(), comp);
        vector<int> res(amount+1, 0);
        res[0] = 1;
        for (const auto &item : coins) {
            for (int i = 1; i < res.size(); ++i) {
                if ( (i-item >= 0) && (res[i-item] != 0)) {
                    int min = 0;
                    if (i-item == 0)
                        min = 1;
                    else
                        min = res[i-item] + 1;
                    if (res[i] == 0)
                        res[i] = min;
                    else if (res[i] > min)
                        res[i] = min;
                }
            }
            int i = 3;
        }
        return res.back() == 0 ? -1:res.back();

    }
};
#endif //P10_P322_找零问题_H
