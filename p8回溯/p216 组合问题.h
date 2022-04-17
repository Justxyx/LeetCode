//
// Created by 肖应雄 on 2022/4/17.
//

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return res;
    }

    void backtracking(int k,int n,int index){
        if (path.size() == k && accumulate(path.begin(),path.end(),0) == n ){
            res.push_back(path);
            return;
        }

        for (int i = index; i <= 9; ++i) {
            path.push_back(i);
            backtracking(k,n,++index);
            path.pop_back();
        }
        return;
    }
};
