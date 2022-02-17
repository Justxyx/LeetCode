//
// Created by 肖应雄 on 2022/2/17.
//

#ifndef P5_P57_H
#define P5_P57_H

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        while ( i < len){
            if (nums[i] == val){
                swap(nums[i],nums[--len]);
            }
            ++ i;
        }
        return len;
    }
};
#endif //P5_P57_H
