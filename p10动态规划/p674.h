//
// Created by xm on 2022/7/1.
//

#ifndef P10_P674_H
#define P10_P674_H
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int sum = 1;
        int maxs = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                ++ sum;
            else {
                maxs = max(sum,maxs);
                sum = 1;
            }
        }
        return max(sum,maxs);
    }
};

#endif //P10_P674_H
