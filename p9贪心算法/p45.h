//
// Created by 肖应雄 on 2022/5/10.
//

#ifndef P9_P45_H
#define P9_P45_H

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
//        int maxDist = 0;
        int count = 0;
//        for (int i = 0; i < nums.size(); ++i) {
        int i = 0;
        while (i < nums.size()){
//            maxDist += nums[i];
            ++ count;

//            if (maxDist >= nums.size())
//                return count;
            if (i+nums[i] >= nums.size()-1)
                break;

            int numSize = nums.size();
            int max = INT_MIN;
            int max_J = 0;
            int s = 0;
            // 寻找最小j值
            for (int j = (i+1); j < min(numSize,i+1+nums[i]); ++j) {
                if (nums[j]+s > max){
                    max_J = j;
                    max = nums[j] + s;
                }
                ++s;
//                cout << max_J;
            }
            i = max_J;
        }
        return count;
    }
};
#endif //P9_P45_H
