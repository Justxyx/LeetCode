//
// Created by 肖应雄 on 2022/1/21.
//

#ifndef P3_A_P454_四数之和_H
#define P3_A_P454_四数之和_H


/**
 * 算法思想：
 *      要三层for循环吗？
 *      1. 遍历 nums1 nums2 数组 一个map存储相加的值与出现次数
 *      2. 同上 遍历 nums3 nums4 数组
 *      3. 0 - （nums3 + nums4） 看是否出现
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map1;
        int count = 0;
        for (const auto &item1 : nums1){
            for (const auto &item2 : nums2){
                if (map1.find(item1 + item2) == map1.end()){
                    // not found
                    map1.insert(make_pair(item1 + item2,1));
                } else{
                    ++map1.find(item1 + item2)->second;
                }
            }
        }

        for (const auto &item3 : nums3){
            for (const auto &item4 : nums4){
                if (map1.find(0 - item3 - item4) != map1.end()){
                    count += map1.find(0 - item3 - item4)->second;
                }
            }
        }
        return count;
    }
};
#endif //P3_A_P454_四数之和_H
