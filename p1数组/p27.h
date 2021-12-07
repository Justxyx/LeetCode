//
// Created by 肖应雄 on 2021/12/7.
//

#ifndef P1_P27_H
#define P1_P27_H

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(),i = 0;
        while (i < len){
            if (nums[i] == val) {
                nums[i] = nums[--len];
                continue;
            }
            ++ i;
        }
        return len;
    }
};


#endif //P1_P27_H
