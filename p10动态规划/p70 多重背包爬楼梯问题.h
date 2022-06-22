//
// Created by xm on 2022/6/22.
//

#ifndef P10_P70_多重背包爬楼梯问题_H
#define P10_P70_多重背包爬楼梯问题_H

class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1,0);
        res[0] = 1;
        for (int i = 1; i < res.size(); ++i) {
            int j = 1;
            while (j <= 2) {
                if (i-j >= 0) {
                    res[i] += res[i-j];
                }
                ++j;
            }
        }
        return res.back();
    }
};
#endif //P10_P70_多重背包爬楼梯问题_H
