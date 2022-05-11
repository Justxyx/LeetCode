//
// Created by 肖应雄 on 2022/5/11.
//

#ifndef P9_P134_加油站问题_H
#define P9_P134_加油站问题_H

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> dup(gas.size());
        for (int i = 0; i < gas.size(); ++i) {
            dup[i] = gas[i] - cost[i];
        }

        int sum = 0;
        int anchor = 0;
        bool b = false;
        for (int i = 0; i < dup.size(); ++i) {
            sum += dup[i];
            if (sum < 0){
                b = true;
                anchor = i;
                sum = 0;
            }
        }
        for (int i = 0; i <= anchor; ++i) {
            sum += dup[i];
        }
        if (sum <0)
            return -1;
        else if (!b)
            return 0;
        else
            return ++anchor;
    }
};

#endif //P9_P134_加油站问题_H
