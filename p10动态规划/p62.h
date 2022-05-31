//
// Created by 肖应雄 on 2022/5/31.
//

#ifndef P10_P62_H
#define P10_P62_H

/*
 * 只能向下或者向右移动
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> index;
        for (int i = 0; i < m; ++i) {
            vector<int> bind(n,0);
            index.push_back(bind);
        }
        index[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            index[i][0] = 1;
            for (int j = 1; j < n; ++j) {
                if (i == 0)
                    index[i][j] = 1;
                else{
                    index[i][j] = index[i-1][j] + index[i][j-1];
                }
            }
        }
        return index.back().back();
    }
};

#endif //P10_P62_H
