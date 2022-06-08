//
// Created by 肖应雄 on 2022/6/8.
//

#ifndef P10_P1049_H
#define P10_P1049_H

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<int> bind(sum/2+1,0);
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = 1; j < bind.size(); ++j) {
                if ((bind[j] == 1) && ((j+stones[i]) < bind.size()) && (bind[j+stones[i]] == 0))
                    bind[j+stones[i]] = -1;
            }
            if (stones[i] < bind.size())
                bind[stones[i]] = 1;
            for (auto &item : bind){
                if (item == -1)
                    item = 1;
            }
        }
        for (int i = bind.size()-1; i >= 0 ; --i) {
            if (bind[i] == 1)
                return sum - 2*i;
        }
        return stones[0];
    }

};
#endif //P10_P1049_H
