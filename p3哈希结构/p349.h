//
// Created by 肖应雄 on 2022/1/18.
//

#ifndef P3_P349_H
#define P3_P349_H
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        unordered_set<int> res;
        for (const auto &item : nums2){
            if (s.find(item) != s.end())
                res.insert(item);
        }
        return vector<int>(res.begin(),res.end());
    }
};
#endif //P3_P349_H
