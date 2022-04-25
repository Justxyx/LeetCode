//
// Created by 肖应雄 on 2022/4/25.
//



class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtracking(nums,0);
        return res;
    }

    void backtracking(vector<int> &nums,int index){
        if (index > nums.size())
            return;
        if (std::find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }

        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }
};







