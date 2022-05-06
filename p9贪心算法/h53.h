//
// Created by 肖应雄 on 2022/5/6.
//

#ifndef P9_H53_H
#define P9_H53_H
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 主要思想 寻找每一个递增序列
        int max = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            // 递增序列
            if (nums[i] > nums[i-1]){
                if (sum < 0){
                    sum = nums[i];
                } else{
                    sum += nums[i];
                }
            } else{
                if ((sum + nums[i]) > 0){
                    sum += nums[i];
                } else
                {
                    sum = nums[i];
                }
            }
            if (sum > max)
                max = sum;
        }
        return max;
    }
};

#endif //P9_H53_H
