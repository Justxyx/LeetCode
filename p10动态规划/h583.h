//
// Created by xm on 2022/7/4.
//

#ifndef P10_H583_H
#define P10_H583_H
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size())
            word1.swap(word2);

        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        int max_dp = 0;

        for (int i = 0; i < word1.size(); ++i) {
            for (int j = 0; j < word2.size(); ++j) {

                if (word1[i] == word2[j]) {
                    i > 0 && j >0 ? dp[i][j] = dp[i-1][j-1] + 1 : dp[i][j] = 1;

                } else {
                    if (i > 0 && j > 0)
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    else if ( i != 0 && j == 0)
                        dp[i][j] = dp[i-1][j];
                    else if (j != 0)
                        dp[i][j] = dp[i][j-1];
                }
                max_dp = max(max_dp, dp[i][j]);
            }

            bool b = true;

            for (const auto &item : dp[i]) {
                if (item != 0){
                    b = false;
                    break;
                }
            }
            if (b && i != 0) {
                dp[i] = dp[i-1];
            }
        }


        if (max_dp == word2.size() || max_dp == word1.size()){
            return abs((int) (word1.size() - word2.size()));
        }
        cout << word1.size() << endl;
        cout << word2.size() << endl;
        return word1.size() + word2.size() - 2 * max_dp;


    }
};
#endif //P10_H583_H
