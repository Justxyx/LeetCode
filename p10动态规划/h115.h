//
// Created by xm on 2022/7/4.
//

#ifndef P10_H115_H
#define P10_H115_H
class Solution {
public:
    int numDistinct(string s, string t) {
        s.swap(t);
        if (s.empty() || t.empty())
            return 0;
        vector<vector<uint64_t>> dp(s.size(), vector<uint64_t>(t.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                // 第一排
                if ( i == 0) {
                    if (s[i] == t[j]) {
                        if (j==0)
                            dp[i][j] = 1;
                        else {
                            dp[i][j] = dp[i][j-1] + 1;
                        }
                    } else {
                        if (j == 0)
                            continue;
                        dp[i][j] = dp[i][j-1];
                    }
                }
                    // 非第一排
                else {

                    if (j == 0)
                        continue;
                    else {
                        if (s[i] == t[j]){
                            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                        } else{
                            dp[i][j] = dp[i][j-1];
                        }
                    }

                }
            }

        }


        return dp.back().back();
    }
};

#endif //P10_H115_H
