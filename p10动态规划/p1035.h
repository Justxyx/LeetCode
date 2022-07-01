//
// Created by xm on 2022/7/1.
//

#ifndef P10_P1035_H
#define P10_P1035_H
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),0));
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    if (i > 0 && j > 0)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 1;
                } else {
                    int pre = 0;
                    if (i > 0)
                        pre = max(pre, dp[i-1][j]);
                    if (j > 0)
                        pre = max(pre, dp[i][j-1]);
                    dp[i][j] = pre;
                }
            }
        }
        return dp.back().back();
    }
};
#endif //P10_P1035_H
