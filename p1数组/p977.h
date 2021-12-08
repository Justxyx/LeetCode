//
// Created by 肖应雄 on 2021/12/8.
//

#ifndef P1_P977_H
#define P1_P977_H

// 1. 暴力解法
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        for ( auto &item : nums)
//            item = pow(item,2);
//        sort(nums.begin(), nums.end());
//        return nums;
//    }
//};

//2. 双指针发
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> num(nums.size(),0);
        int p = nums.size() - 1;
        int s = 0,e = p;
        while ( s <= e){
            if (pow(nums[s],2) > pow(nums[e],2))
                num[p--] = pow(nums[s++],2);
            else
                num[p--] = pow(nums[e--],2);
        }
        return num;
    }
};

#endif //P1_P977_H
