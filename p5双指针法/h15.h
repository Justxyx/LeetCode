//
// Created by 肖应雄 on 2022/2/23.
//
/**
 * 这题要再刷十遍！！！！！！！！！
 *
 * 第二次刷了，刷了俩小时。
 * 用传统的算法写，有无数个需要注意的边界问题！ 无数个！！！！！！！！！！！！
 */
#ifndef P5_H15_H
#define P5_H15_H
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int left,right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i>0 && nums[i] == nums[i-1] )
                continue;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] > 0){
                    -- right;
                } else if ( nums[i] + nums[left] + nums[right] < 0){
                    ++left;
                } else{
                    v.push_back({nums[i],nums[left],nums[right]});
                    while (left< right && nums[left] == nums[left+1])
                        left ++ ;
                    while (left< right && nums[right] == nums[right-1])
                        right--;
                    ++left;
                    --right;
                }
            }
        }
        return v;
    }
};

#endif //P5_H15_H
