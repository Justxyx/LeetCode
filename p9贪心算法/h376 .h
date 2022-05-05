//
// Created by 肖应雄 on 2022/5/6.
//

#ifndef P9_H376_H
#define P9_H376_H
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 1;


        int i = 1;
        bool more = true;
        while (i < nums.size()){
            if (i == 1){
                while (i < nums.size() && nums[i] == nums[0]){
                    ++i;
                }
                if(i >= nums.size())
                    break;
                if (nums[i] > nums[0])
                    more = true;
                else if(nums[i] == nums[0]){
                    more = false;
                    ++i;
                    continue;
                }
                else
                    more = false;
                ++ count;
                ++i;
                continue;
            }

            if ((nums[i] > nums[i-1]) && more){
                more = true;
            } else if ((nums[i] > nums[i-1]) && !more){
                more = true;
                ++ count;
            } else if ((nums[i] < nums[i-1]) && more){
                more = false;
                ++ count;
            } else if (nums[i] == nums[i-1]){
                ++i;
                continue;
            }
            else{
                more = false;
            }
            ++ i;
        }
        return count;
    }
};
#endif //P9_H376_H
