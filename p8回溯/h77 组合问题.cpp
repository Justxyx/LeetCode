//
// Created by 肖应雄 on 2022/4/15.
//

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }

    void backtracking(int n,int k,int index){
        if (path.size() == k){
            res.push_back(path);
            return;
        }

        for (int i = index; i <= n ; ++i) {
            path.push_back(i);
            backtracking(n,k,++index);
            path.pop_back();
        }
        return;
    }
};
