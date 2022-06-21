//
// Created by 肖应雄 on 2022/6/21.
//

#ifndef P10_H377_组合问题_H
#define P10_H377_组合问题_H
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (*min_element(nums.begin(),nums.end()) > target || target == 0)
            return 0;
        vector<int> res(target+1,0);
        res[0] = 1;

        for (int i = 1; i < res.size(); ++i) {
            for (const auto &item : nums) {
                if ((i - item) >= 0 && res[i - item] != 0) {
                    if (res[i-item]  > INT_MAX - res[i])
                        continue;

                    res[i] += res[i-item];
                }
            }
        }
        return res.back();
    }
};
#endif //P10_H377_组合问题_H
