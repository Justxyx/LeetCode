//
// Created by 肖应雄 on 2022/5/10.
//

#ifndef P9_P1005_H
#define P9_P1005_H

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        while ( k > nums.size()){
            k -= 2;
        }

        std::sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (k <= 0)
                break;
            if (nums[i] < 0){
                nums[i] = -nums[i];
                --k;
            } else{
                break;
            }
        }

        if (k > 0 && k%2 == 1 ){
            if (i > 0 && nums[i] > nums[i-1])
                nums[i-1] = -nums[i-1];
            else
                nums[i] = -nums[i];
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};
#endif //P9_P1005_H
