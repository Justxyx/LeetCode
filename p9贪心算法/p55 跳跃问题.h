//
// Created by 肖应雄 on 2022/5/9.
//

#ifndef P9_P55_跳跃问题_H
#define P9_P55_跳跃问题_H


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist = 0;  // 最大可跳跃距离
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > maxDist)
                maxDist = nums[i];
            // 当前值为0
            if (nums[i] == 0){
                if (maxDist > 0)
                    maxDist--;
                else
                    return false;
                continue;
            }

            maxDist --;
        }
        return true;
    }
};
#endif //P9_P55_跳跃问题_H
