//
// Created by xm on 2022/7/4.
//

#ifndef P10_H516_回文2_H
#define P10_H516_回文2_H
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        int count = 0;
        int i = 0;
        int j = 0;
        int maxs = 0;

        while (count < s.size()) {
            j = count;
            for (int k = count; k < s.size(); ++k) {



                /*
                 * 主体代码
                 */
                if (i == j)
                    dp[i][j] = 1;
                else if (abs(i-j) == 1) {
                    if (s[i] == s[j]){
                        dp[i][j] = 2;
                    } else{
                        dp[i][j] = 1;
                    }
                } else if (abs(i-j) == 2) {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    } else {
                        dp[i][j] = max(dp[i+1][j], max(dp[i+1][j-1], dp[i][j-1]));
                    }
                } else{
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    } else{
                        dp[i][j] = max(dp[i+1][j], max(dp[i+1][j-1], dp[i][j-1]));
                    }
                }

                maxs = max(maxs, dp[i][j]);
                ++ i;
                ++ j;
            }
            ++ count;
            i = 0;
        }
        return maxs;
    }
};

#endif //P10_H516_回文2_H
