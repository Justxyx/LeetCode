//
// Created by 肖应雄 on 2022/1/24.
//

#ifndef P3_A_P15_三数之和_H
#define P3_A_P15_三数之和_H

/**
 * 这题真是把人刷无语了
 * 各种考虑边界情况 但是leetcode 还是报错数组边界异常
 * 强烈建议看 p15 的代码注释解读
 * 确实在处理边界问题上 思考的很详细
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                return res;
            if ( i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while ( left < right){
                if ( nums[i] + nums[left] + nums[right] > 0){
                    -- right;
                } else if( nums[i] + nums[left] + nums[right] < 0 )
                {
                    ++ left;
                } else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    while (left < right && nums[left] == nums[left+1])
                        ++ left;
                    while (left < right && nums[right] == nums[right-1])
                        -- right;
                    -- right;
                    ++ left;
                }
            }
        }
        return res;
    }
};
#endif //P3_A_P15_三数之和_H
