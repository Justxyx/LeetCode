//
// Created by xm on 2022/7/4.
//

#ifndef P10_H72_H
#define P10_H72_H

class Solution {
public:
    int minDistance(string word1, string word2) {
        if  (word2.empty() || word1.empty())
            return abs((int)(word2.size() - word1.size()));
        if (word1.size() > word2.size())
            word1.swap(word2);
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));

        word1[0] == word2[0] ? dp[0][0] = 0 : dp[0][0] = 1;
        bool b = true;
        // 初始化
        for (int i = 1; i < word2.size(); ++i) {
            if (word2[i] == word1[0] && b)
            {
                dp[0][i] = dp[0][i-1];
                b = false;
            }
            else
                dp[0][i] = dp[0][i-1] + 1;
        }
        b = true;
        for (int i = 1; i < word1.size(); ++i) {
            if (word1[i] == word2[0] & b) {
                dp[i][0] = dp[i-1][0];
                b = false;
            } else
                dp[i][0] = dp[i-1][0] + 1;
        }

        int d1,d2,d3;
        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    // 改
                    d1 = dp[i-1][j-1] + 1;
                    // 删
                    d2 = dp[i-1][j] + 1;
                    // 增
                    d3 = dp[i][j-1] + 1;
                    dp[i][j] = min(min(d1,d2), d3);
                }
            }

        }
        return dp.back().back();
    }
};
#endif //P10_H72_H
