//
// Created by xm on 2022/9/6.
//

#ifndef P12__P3_数组_H
#define P12__P3_数组_H

class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while ( left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = left;
        while ( left < nums.size() && right < nums.size()) {
            if (nums[right] == val) {
                ++ right;
                continue;
            }

            swap(nums[left++], nums[right++]);
        }
        nums.resize(left);
        return left;
    }
};

class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> res(nums.size(), 0);
        int count = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right]))
                res[count--] = pow((nums[right--]),2) ;
            else
                res[count--] = pow(abs(nums[left++]), 2);
        }
        return res;
    }
};

class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 0) < target)
            return 0;
        int left = 0;
        int right = 0;
        int sum = nums[0];
        int mins = INT_MAX;
        int count = 1;
        while (left < nums.size() && right < nums.size()) {
            if (sum >= target) {
                mins = min(mins, count);
                sum -= nums[left];
                ++ left;
                -- count;
            } else {
                if (right == nums.size())
                    break;
                sum += nums[++right];
                ++ count;
            }
        }
        return mins;
    }
};


#endif //P12__P3_数组_H
