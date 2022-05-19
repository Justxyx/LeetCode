//
// Created by 肖应雄 on 2022/5/19.
//

#ifndef P9_P435_H
#define P9_P435_H

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), comp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] == left){
                ++ count;
                continue;
            } else if (intervals[i][0]>= right){
                left = intervals[i][0];
                right = intervals[i][1];
                continue;
            } else{
                if (intervals[i][1] < right){
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
                ++ count;
            }
        }
        return count;
    }
    static bool comp(const vector<int> &v1,const vector<int> &v2){
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
};

#endif //P9_P435_H
