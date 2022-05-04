//
// Created by 肖应雄 on 2022/5/4.
//

#ifndef P9_P455_分饼干问题_H
#define P9_P455_分饼干问题_H

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        if (g.empty() || s.empty())
            return count;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0 , j = 0;
        while (i < g.size() && j < s.size()){
            if (g[i] <= s[j]){
                ++ count;
                ++i;
                ++j;
            } else{
                ++j;
            }
        }
        return count;
    }
};
#endif //P9_P455_分饼干问题_H
