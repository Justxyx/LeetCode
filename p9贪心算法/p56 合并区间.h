//
// Created by 肖应雄 on 2022/5/23.
//

#ifndef P9_P56_合并区间_H
#define P9_P56_合并区间_H


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), comp);
        int right = intervals[0][1];
        int left = INT_MIN;
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (left == INT_MIN){
                left = intervals[i][0];
                right = intervals[i][1];
                continue;
            }
            if (intervals[i][0] == left)
                continue;
            if (intervals[i][0] >= left && intervals[i][0] <= right){
                if (intervals[i][1] <= right)
                    continue;
                else
                    right = intervals[i][1];
                continue;
            }
            res.push_back({left,right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
        res.push_back({left,right});

        return res;
    }

    static bool comp(const vector<int> &v1,const vector<int> &v2){
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
};
#endif //P9_P56_合并区间_H
