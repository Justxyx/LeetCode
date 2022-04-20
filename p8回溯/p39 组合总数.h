//
// Created by 肖应雄 on 2022/4/20.
//

#ifndef P8_P39_组合总数_H
#define P8_P39_组合总数_H

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backbracking(candidates,target,0);
        return res;
    }

    void backbracking(vector<int> &candidatex,int target,int index){
        if (accumulate(path.begin(),path.end(),0) > target){
            return;
        }
        if (accumulate(path.begin(),path.end(),0) == target){
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidatex.size(); ++i) {
            path.push_back(candidatex[i]);
            backbracking(candidatex,target,i);
            path.pop_back();
        }
        return;
    }

};

#endif //P8_P39_组合总数_H
