//
// Created by 肖应雄 on 2022/4/21.
//

#ifndef P8_H40_H
#define P8_H40_H


class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates,target,0);
        return res;
    }
    void backtracking(vector<int> &candidates,int target,int index){

        if (accumulate(path.begin(),path.end(),0) > target)
            return;

        if (accumulate(path.begin(),path.end(),0) == target) {
            if (std::find(res.begin(), res.end(), path) == res.end()){
                res.push_back(path);
            }
        }

        for (int i = index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtracking(candidates,target,i + 1);
            path.pop_back();
            while (i+1 < candidates.size() && candidates[i] == candidates[i+1])
                ++i;
        }
        return;
    }
};
#endif //P8_H40_H
