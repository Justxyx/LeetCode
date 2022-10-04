//
// Created by xm on 2022/10/4.
//

#ifndef P12__P5_哈希_H
#define P12__P5_哈希_H

class Solution242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> bind_s(26, 0);
        vector<int> bind_t(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++bind_s[s[i] - 97];
            ++bind_t[t[i] - 97];
        }
        for (int i = 0; i < 26; ++i) {
            if (bind_s[i] != bind_t[i])
                return false;
        }
        return true;
    }
};

class Solution1002 {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> bind(26, 0);
        vector<int> cur(26, 0);

        for (const auto &item : words[0]) {
            ++bind[item-97];
        }

        for (int i = 1; i < words.size(); ++i) {
            for (const auto &item : words[i]) {
                ++cur[item-97];
            }
            for (int j = 0; j < 26; ++j) {
                bind[j] = min(bind[j], cur[j]);
                cur[j] = 0;
            }

        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            if (bind[i] != 0) {
                for (int j = 0; j < bind[i]; ++j) {
                    res.push_back(string(1, (char)(i+97)));
                }
            }
        }
        return res;
    }
};

class Solution202 {
public:
    bool isHappy(int n) {
        long long n_l = n;
        for (int i = 0; i < 1000; ++i) {
            n_l = judge(n_l);
            if (n_l == 1)
                return true;
        }
        return false;
    }
    long long judge(long long x) {
        long long s = 0;
        while (x > 0) {
            s += pow((x%10), 2);
            if (s > INT_MAX)
                return s;
            x /= 10;
        }
        return s;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> bind;
        for (int i = 0; i < nums.size(); ++i) {
            if (bind.find(target-nums[i]) == bind.end())
                bind.insert(make_pair(nums[i], i));
            else {
                res.push_back(bind.find(target-nums[i])->second);
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> bind;
        for (const auto &item1 : nums1) {
            for (const auto &item2 : nums2) {
                ++ bind[item2+item1];
            }
        }

        int res = 0;
        for (const auto &item3 : nums3) {
            for (const auto &item4 : nums4) {
                int temp = -(item3 + item4);
                res += bind[temp];
            }
        }
        return res;
    }
};

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size())
            return false;
        vector<int> bind(26, 0);
        for (const auto &item : ransomNote) {
            ++bind[item-97];
        }
        int count = ransomNote.size();
        for (int i = 0; i < magazine.size(); ++i) {
            if (count == 0)
                break;
            if (bind[magazine[i] - 97] != 0) {
                -- count;
                -- bind[magazine[i] - 97];
            }
        }
        if (count == 0)
            return true;
        else
            return false;
    }
};


class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right;
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i-1] == nums[i])
                continue;
            left = i+1;
            right = nums.size() - 1;
            while (left < right) {
                if (left != i+1 && nums[left] == nums[left-1]) {
                    ++ left;
                    continue;
                }
                if (right != nums.size()-1 && nums[right] == nums[right+1]) {
                    -- right;
                    continue;
                }
                if (nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++ left;
                    -- right;
                }
                else if (nums[left] + nums[right] + nums[i] < 0)
                    ++ left;
                else
                    -- right;
            }
        }
        return res;
    }
};

#endif //P12__P5_哈希_H
