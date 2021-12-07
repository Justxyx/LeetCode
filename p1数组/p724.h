//
// Created by 肖应雄 on 2021/12/7.
//

#ifndef P1_P724_H
#define P1_P724_H
// 704
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int b = 0, e = nums.size() - 1;
        int mid;
        while (b <= e) {
            mid = (e - b) / 2 + b;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                e = mid - 1;
            else
                b = mid + 1;
        }
        return -1;
    }
};
#endif //P1_P724_H
