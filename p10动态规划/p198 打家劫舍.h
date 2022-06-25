//
// Created by xm on 2022/6/25.
//

#ifndef P10_P198_打家劫舍_H
#define P10_P198_打家劫舍_H

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size() == 1 ? nums.front() : *max_element(nums.begin(),nums.begin()+2);
        vector<int> bind(nums.size(),0);
        bind[0] = nums.front();
        bind[1] = *max_element(nums.begin(),nums.begin()+2);
        for (int i = 2; i < nums.size(); ++i) {
            bind[i] = max(bind[i-1], bind[i-2] + nums[i]);
        }
        return nums.back();
    }
};
#endif //P10_P198_打家劫舍_H
