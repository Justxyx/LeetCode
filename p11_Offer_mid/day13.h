//
// Created by xm on 2022/7/19.
//

#ifndef P11_OFFER_MID_DAY13_H
#define P11_OFFER_MID_DAY13_H

class Solution1 {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return nums;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left]%2 == 1)
                ++ left;
            else if (nums[right]%2 == 0)
                -- right;
            else {
                swap(nums[left], nums[right]);
                ++ left;
                -- right;
            }
        }
        return nums;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty())
            return nums;
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left <= right) {
            if (nums[left] + nums[right] > target)
                --right;
            else if (nums[left] + nums[right] < target)
                ++ left;
            else{
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            swap(s[i],s[s.size()-i-1]);
        }

        int begin = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                int temp = i-1;
                while (begin <= temp) {
                    swap(s[begin++], s[temp--]);
                }
                begin = i+1;
            }
        }
        cout << s << endl;

        int left = 0;
        bool flag = false;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                s[left++] = s[i];
                flag = true;
            } else {
                if (flag) {
                    s[left++] = ' ';
                    flag = false;
                }
            }
        }

        if (left-1 < s.size() && s[left-1] == ' ')
            s.resize(--left);
        else
            s.resize(left);
        return s;
    }
};
#endif //P11_OFFER_MID_DAY13_H
