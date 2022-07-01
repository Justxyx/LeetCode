//
// Created by xm on 2022/7/1.
//

#ifndef P10_H_300_H
#define P10_H_300_H

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bind(nums.size(),1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    bind[i] = max(bind[i],bind[j] + 1);
            }
        }
        return *std::max_element(bind.begin(), bind.end());
    }
};
#endif //P10_H_300_H
