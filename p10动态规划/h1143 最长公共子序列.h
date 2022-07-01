//
// Created by xm on 2022/7/1.
//

#ifndef P10_H1143_最长公共子序列_H
#define P10_H1143_最长公共子序列_H

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),0));

        int pre = 0;
        for (int i = 0; i < text1.size(); ++i) {
            if (i == 2)
            {

            }
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] == text2[j]){
                    if ( i-1 >= 0 && j-1 >= 0)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 1;
                } else{
                    if (i > 0)
                        pre = max(dp[i-1][j],pre);
                    if (j > 0)
                        pre = max(dp[i][j-1],pre);
                    dp[i][j] = pre;
                }
                pre = 0;
            }
        }

        for (const auto &item : dp){
            for (const auto &i : item)
                cout << i << ",";
            cout << endl;
        }

        return dp.back().back();
    }
};

#endif //P10_H1143_最长公共子序列_H
