//
// Created by xm on 2022/7/1.
//

#ifndef P10_H718_最长重复子数组_H
#define P10_H718_最长重复子数组_H

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> bind(nums1.size(), vector<int>(nums2.size(), 0));
        int pre = 0;
        int max_value = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (i-1 < 0 || j - 1 < 0)
                    pre = 0;
                else
                    pre = bind[i-1][j-1];

                if (nums1[i] == nums2[j])
                    bind[i][j] = pre + 1;
                max_value = max(bind[i][j], max_value);
            }
        }
        return max_value;
    }
};
#endif //P10_H718_最长重复子数组_H
