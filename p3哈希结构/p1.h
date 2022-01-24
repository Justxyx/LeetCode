//
// Created by 肖应雄 on 2022/1/21.
//

#ifndef P3_P1_H
#define P3_P1_H

/**
 * 算法思想：
 *      并不需要key有序  所以采用unordered_map比较合适
 *      依次遍历加入 unordered_map 中  target 依次减掉元素 看剩余差值是否还存在于map中
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto ptr = map.find((target - nums[i]));
            if ( ptr == map.end()){
                // has not found;
                map.insert(make_pair(nums[i],i));
            } else{
                return {ptr->second,i};
            }
        }
        return {};
    }
};

#endif //P3_P1_H
