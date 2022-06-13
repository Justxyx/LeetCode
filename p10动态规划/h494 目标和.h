//
// Created by 肖应雄 on 2022/6/13.
//

#ifndef P10_H494_目标和_H
#define P10_H494_目标和_H

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        /*
         * right
         * left
         *
         * right + left = target
         * right - left = sum
         */
        int right = (sum + target) / 2;
        if ( (sum + target) % 2 == 1)
            return 0;
        if (abs(target)  > sum)
            return 0;
        vector<int> bind(right+1,0);
        vector<int> temp(right+1,0);
        bind[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < bind.size(); ++j) {
                if (bind[j] != 0 && j + nums[i] <= right){
                    int s1 = bind[j];
                    int s2 = nums[i];
                    temp[j + nums[i]] += bind[j];
                }
            }
            for (int j = 0; j < bind.size(); ++j) {
                bind[j] += temp[j];
                temp[j] = 0;
            }
        }
        return bind.back();
    }
};

#endif //P10_H494_目标和_H
