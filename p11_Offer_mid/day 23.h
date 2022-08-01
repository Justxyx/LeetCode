//
// Created by xm on 2022/8/1.
//

#ifndef P11_OFFER_MID_DAY_23_H
#define P11_OFFER_MID_DAY_23_H

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == res)
                ++ count;
            else
                -- count;
            if (count == 0) {
                res = nums[i];
                ++ count;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> left(a.size(), 1),
                right(a.size(), 1);

        for (int i = 1; i < a.size(); ++i) {
            left[i] = a[i-1] * left[i-1];
        }
        for (int i = a.size()-2; i >= 0; --i) {
            right[i] = a[i+1] * right[i+1];
        }
        vector<int> res(a.size(), 0);
        for (int i = 0; i < a.size(); ++i) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
#endif //P11_OFFER_MID_DAY_23_H
