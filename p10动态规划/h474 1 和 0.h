//
// Created by 肖应雄 on 2022/6/16.
//

#ifndef P10_H474_1_和_0_H
#define P10_H474_1_和_0_H
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> bind(m+1,vector<int>(n+1,0));
        for (const auto &item : strs) {
            int count_0 = 0;
            int count_1 = 0;
            for (const auto &i : item) {
                if (i == '0')
                    ++ count_0;
                else
                    ++ count_1;
            }
            for (int i = m; i >= count_0 ; --i) {
                for (int j = n; j >= count_1 ; --j) {
                    bind[i][j] = max(bind[i][j],bind[i-count_0][j-count_1]+1);
                }
            }
        }
        return bind.back().back();
    }
};
#endif //P10_H474_1_和_0_H
