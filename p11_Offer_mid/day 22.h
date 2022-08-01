//
// Created by xm on 2022/8/2.
//

#ifndef P11_OFFER_MID_DAY_22_H
#define P11_OFFER_MID_DAY_22_H
class Solution1 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (const auto &item : nums) {
            sum ^= item;
        }

        int flag = 1;
        int c = sum & flag;

        while ((sum & flag) == 0) {
            flag = flag << 1;
        }

        // 分组 这个太难想了
        int a = 0, b = 0;
        for (const auto &item : nums) {
            if (item & flag)
                a ^= item;
            else
                b ^= item;
        }
        return vector<int>{a,b};
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        std::sort(nums.begin(), nums.end());
        if (nums[nums.size() -1] != nums[nums.size()-2])
            return nums.back();
        if (nums[0] != nums[1])
            return nums[0];
        for (int i = 1; i < nums.size()-1; ++i) {
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        }
        return 0;
    }
};

#endif //P11_OFFER_MID_DAY_22_H
