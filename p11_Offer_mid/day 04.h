//
// Created by xm on 2022/7/11.
//

#ifndef P11_OFFER_MID_DAY_04_H
#define P11_OFFER_MID_DAY_04_H
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] == nums[i-1])
                return nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0] == target ? 1 : 0;
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        int count = 0;
        while ( begin <= end) {
            if (begin == end){
                mid = begin;
                break;
            }
            mid = (begin+end)/2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                end = mid;
            else
                begin = mid + 1;
        }
        if (nums[mid] != target)
            return 0;
        else {
            int i = 0;
            while ( mid - i >= 0 && nums[mid-i] == target)
            {
                ++ count;
                ++ i;
            }
            i = 1;
            while ( mid + i < nums.size() && nums[mid+i] == target) {
                ++ count;
                ++ i;
            }
        }
        return count;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while (begin < end) {
            mid = (begin+end)/2;
            if (nums[mid] == mid)
                begin = mid+1;
            else
                end = mid;
        }
        while (mid < nums.size() && nums[mid] == mid)
            ++ mid;
        return mid;
    }
};
#endif //P11_OFFER_MID_DAY_04_H
