//
// Created by 肖应雄 on 2022/4/24.
//

#ifndef P8_P78_子集_H
#define P8_P78_子集_H

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }

    void backtracking(vector<int> &nums,int index){
        if (index > nums.size())
            return;
        res.push_back(path);

        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }
};

#endif //P8_P78_子集_H
