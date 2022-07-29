//
// Created by xm on 2022/7/29.
//

#ifndef P11_OFFER_MID_排序_H
#define P11_OFFER_MID_排序_H

/*
 * 1. 插入类排序
 */
// 直接插入排序
class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int temp = nums[i];
            int j = i-1;
            while (j >= 0 && nums[j] > temp) {
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = temp;
        }
        return nums;
    }
};
// 折半插入排序
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int temp = nums[i];
            int left = 0, right = i;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (nums[mid] < temp)
                    left = mid + 1;
                else
                    right = mid;
            }
            right = i-1;
            while (right >= left ) {
                nums[right+1] = nums[right];
                --right;
            }
            nums[left] = temp;
        }
        return nums;
    }
};
// 希尔排序

/*
 * 2. 交换类排序
 */
// 1. 冒泡排序
class Solution3 {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = nums.size()-1; j > i ; --j) {
                if (nums[j] < nums[j-1])
                    swap(nums[j], nums[j-1]);
            }
        }
        return nums;
    }
};
// 2. 快排  分治
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        doback(nums, 0, nums.size()-1);
        return nums;
    }
    void doback(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;
        int index = doTo2(nums, left, right);
        doback(nums, left, index-1);
        doback(nums, index+1, right);
    }
    int doTo2(vector<int> &nums, int left, int right) {
        int temp = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= temp)
                -- right;
            nums[left] = nums[right];
            while (left < right && nums[left] < temp)
                ++ left;
            nums[right] = nums[left];
        }
        nums[left] = temp;
        return left;
    }
};

#endif //P11_OFFER_MID_排序_H
