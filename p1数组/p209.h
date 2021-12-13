//
// Created by 肖应雄 on 2021/12/13.
//

#ifndef P1_P209_H
#define P1_P209_H

// p209
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int min = 0;
        int sum = nums[i];
        while (j < nums.size()){

            if (sum >= target){
                if (min == 0){
                    min = j - i + 1;
                } else{
                    if (min > (j - i + 1)){
                        min = j - i + 1;
                    }
                }
                if ( i < j ) {
                    sum = sum - nums[i ++];
                } else
                {
                    if (j == nums.size()-1)
                        break;
                    sum = sum + nums[++j];
                }
            } else  {
                if (j == nums.size()-1)
                    break;
                sum = sum + nums[++j];

            }
        }
        return min;
    }
};
#endif //P1_P209_H
