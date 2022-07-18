//
// Created by xm on 2022/7/18.
//

#ifndef P11_OFFER_MID_DAY09_H
#define P11_OFFER_MID_DAY09_H

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int has = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            // 取  不取？
            has = max(has+nums[i], nums[i]);
            res = max(res, has);
        }
        return res;
    }
};


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};

#endif //P11_OFFER_MID_DAY09_H
