//
// Created by xm on 2022/7/4.
//

#ifndef P10_H647_回文串_H
#define P10_H647_回文串_H

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        int i = 0;
        int j = 0;

        int count = 0;
        int sum = 0;
        while (count <= s.size()) {
            int temp_j = j;
            for (int k = count; k < s.size(); ++k) {

                if (i == j) {
                    dp[i][j] = 1;
                    ++ sum;
                } else if (abs(i-j) <= 2) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        ++ sum;
                    }
                } else {

                    if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        ++ sum;
                    }

                }



                i ++;
                j ++;
            }

            i = 0;
            j = temp_j + 1;
            ++ count;
        }
        return sum;
    }
};

#endif //P10_H647_回文串_H
