//
// Created by xm on 2022/7/1.
//

#ifndef P10_P718_H
#define P10_P718_H
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty() )
            return true;
        if (t.empty())
            return false;

        vector<vector<int>> dp(s.size(), vector<int>(t.size(),0));

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (s[i] == t[j]){

                    if ( i != 0 && j != 0)
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = 1;

                } else {
                    if (j != 0)
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        for (const auto &item : dp) {
            for (const auto &i : item)
                cout << i << ",";
            cout << endl;
        }
        for (const auto &item : dp.back()){
            if ( item == 1)
                return true;
        }
        return false;
    }
};
#endif //P10_P718_H
