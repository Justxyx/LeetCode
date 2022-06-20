//
// Created by 肖应雄 on 2022/6/20.
//

#ifndef P10_P518_多重背包_找硬币问题_H
#define P10_P518_多重背包_找硬币问题_H

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        vector<int> bind(amount+1, 0);
        bind[0] = 1;
        for (const auto &item : coins) {
            for (int i = 1; i < bind.size(); ++i) {
                if ((i-item) >= 0 && bind[i-item] != 0) {
                    bind[i] += bind[i-item];
                }
            }
        }
        return bind.back();
    }
};
#endif //P10_P518_多重背包_找硬币问题_H
