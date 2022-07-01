//
// Created by xm on 2022/7/1.
//

#ifndef P10_P53_最大子数组和_H
#define P10_P53_最大子数组和_H

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.front();
        int maxs = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if ( sum < 0)
                sum = nums[i];
            else
                sum += nums[i];

            maxs = max(sum, maxs);
        }
        return maxs;
    }
};

#endif //P10_P53_最大子数组和_H
