//
// Created by 肖应雄 on 2022/4/26.
//

#ifndef P8_P491_H
#define P8_P491_H

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }

    void backtracking(vector<int> &nums,int index){

        if (index > nums.size())
            return;
        if (path.size() >= 2 ){
            res.push_back(path);
        }
        set<int> sets;
        for (int i = index; i < nums.size(); ++i) {
            if (sets.find(nums[i]) != sets.end())
                continue;
            sets.insert(nums[i]);
            if (path.empty()){
                path.push_back(nums[i]);
            } else if (nums[i] >= path.back()){
                path.push_back(nums[i]);
            } else{
                continue;
            }
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }
};

#endif //P8_P491_H
