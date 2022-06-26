//
// Created by xm on 2022/6/27.
//

#ifndef P10_P231_继续打家劫舍_H
#define P10_P231_继续打家劫舍_H

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size() == 1 ? nums.front() : *max_element(nums.begin(),nums.begin()+2);
        if (nums.size() == 3)
            return *max_element(nums.begin(),nums.end());
        vector<int> replace;
        int maxs = 0;
        vector<int> bind(nums.size(),0);
        for (int i = 0; i < nums.size(); ++i) {
            replace = vector<int>(nums.begin()+i,nums.end());
            for (int j = 0; j < i; ++j) {
                replace.push_back(nums[j]);
            }

            bind[0] = replace.front();
            bind[1] = *max_element(replace.begin(),replace.begin()+2);
            bool isFirst = true;
            if (bind[1] > bind[0])
                isFirst = false;
            for (int i = 2; i < replace.size(); ++i) {
                // 处理最后一个数
                if (i == replace.size() - 1) {
                    if (isFirst) {
                        bind[i] = bind[i-1];
                    } else {
                        bind[i] = max(bind[i-1], bind[i-2] + replace[i]);
                    }
                } else {
                    bind[i] = max(bind[i - 1], bind[i - 2] + replace[i]);
                    if ((i == 2) && (bind[i-2] + replace[i] > bind[i-1]))
                        isFirst = true;
                }
            }

            if (maxs < bind.back())
                maxs = bind.back();
        }
        return maxs;
    }
};
#endif //P10_P231_继续打家劫舍_H
