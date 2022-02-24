//
// Created by 肖应雄 on 2022/2/24.
//

#ifndef P5_H18_H
#define P5_H18_H


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int i,d;
        int left,right;
        int res = 0;
        long l = 0;

        if (target < nums[0] && target > 0)
            return vector<vector<int>>();

        for(d = 0;d < nums.size(); d++){
            if (d> 0 && nums[d] == nums[d-1])
                continue;


            res = target - nums[d];
            // 三数之和
            for (int i = d+1; i < nums.size(); ++i) {
                if (i-1>d && nums[i] == nums[i-1] )
                    continue;
                left = i + 1;
                right = nums.size() - 1;
                while (left < right){
//                    l = nums[i] + nums[left] + nums[right];
                    if (nums[i] + nums[left] > res - nums[right]){
                        -- right;
                    } else if ( nums[i] + nums[left] < res - nums[right]  ){
                        ++left;
                    } else{
                        v.push_back({nums[d],nums[i],nums[left],nums[right]});
                        while (left< right && nums[left] == nums[left+1])
                            left ++ ;
                        while (left< right && nums[right] == nums[right-1])
                            right--;
                        ++left;
                        --right;
                    }
                }
            }



        }
        return v;

    }
};


#endif //P5_H18_H
