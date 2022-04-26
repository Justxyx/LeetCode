//
// Created by 肖应雄 on 2022/4/26.
//

#ifndef P8_P46_排列_H
#define P8_P46_排列_H

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums);
        return res;
    }

    void backtracking(vector<int> &nums){
        if (nums.empty()){
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            vector<int> back = nums;
            back.erase(std::find(back.begin(), back.end(), nums[i]));
            backtracking(back);
            path.pop_back();
        }
        return;
    }
};

#endif //P8_P46_排列_H
