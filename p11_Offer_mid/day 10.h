//
// Created by xm on 2022/7/19.
//

#ifndef P11_OFFER_MID_DAY_10_H
#define P11_OFFER_MID_DAY_10_H

class Solution1 {
public:
    int translateNum(int num) {
        vector<int> nums;
        if (num < 10)
            return 1;
        else {
            while (num > 0) {
                nums.push_back(num%10);
                num = num/10;
            }
        }
        reverse(nums.begin(), nums.end());
//        for (const auto &item : nums)
//            cout << item << endl;
        vector<int> dp(nums.size(), 0);
        /*
         * 12  24   32
         */
        dp[0] = 1;
        if (nums[0] < 2 || (nums[0] < 3 && nums[1] < 6))
            dp[1] = 2;
        else
            dp[1] = 1;
        for (int i = 2; i < dp.size(); ++i) {
            if (nums[i-1] < 3 && nums[i] < 6) {
                if (nums[i-1] != 0)
                    dp[i] = dp[i-2];
            }else if (nums[i-1] == 1)
                dp[i] = dp[i-2];
            dp[i] += dp[i-1];
        }
        return dp.back();
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int left = 0;
        int right = 0;
        set<char> sets;
        int maxs = 0;
        while (right < s.size()) {
            if (sets.find(s[right]) == sets.end()) {
                sets.insert(s[right]);
                ++ right;
            } else {
                sets.erase(sets.find(s[left]));
                ++ left;
            }
            maxs = max(right - left, maxs);
        }
        return maxs;
    }
};
#endif //P11_OFFER_MID_DAY_10_H
