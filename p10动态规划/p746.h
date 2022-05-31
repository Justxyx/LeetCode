//
// Created by 肖应雄 on 2022/5/30.
//

#ifndef P10_P746_H
#define P10_P746_H

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> index(cost.size(),0);
        index[0] = cost[0];
        index[1] = cost[1];
        if (cost.size() <= 2)
            return min(index[0],index[1]);
        int i;
        for (i = 2; i < cost.size(); ++i) {
            index[i] = min(index[i-1],index[i-2]) + cost[i];
        }
        return min(index[i-1],index[i-2]);
    }
};
#endif //P10_P746_H
