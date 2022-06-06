//
// Created by 肖应雄 on 2022/6/6.
//

#ifndef P10_P416_H
#define P10_P416_H
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum % 2 == 1)
            return false;
        for (const auto &item : nums){
            if (item > sum / 2)
                return false;
        }
        vector<int> bind(sum/2+1,0);
        for (const auto &item : nums){
            for (int i = 1; i <= sum/2; ++i) {
                if ((bind[i] == 1) && ((i + item) <= sum/2)){
                    if (bind[item+i] == 0)
                        bind[item+i] = -1;
                }
            }
            for (auto &item : bind){
                if (item == -1)
                    item = 1;
            }
            if (bind[item] == 0)
                bind[item] = 1;
            if (bind.back() == 1)
                return true;
        }
        return false;
    }
};
#endif //P10_P416_H
