//
// Created by 肖应雄 on 2022/5/18.
//

#ifndef P9_P135_分发糖果_H
#define P9_P135_分发糖果_H
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(),1);
        // 第一次遍历
        for (int i = 0; i < ratings.size(); ++i) {
            if (i == 0){
                res[i] = 1;
            } else{
                if (ratings[i] > ratings[i-1])
                    res[i] = res[i-1] + 1;
            }
        }
        // 第二次遍历
        for (int i = ratings.size() - 1; i>= 0; --i) {
            if ( i == (ratings.size() - 1))
                continue;
            if (ratings[i] > ratings[i+1]){
                if (res[i] < (res[i+1] + 1))
                    res[i] = res[i+1] +1;
            }
        }
        return accumulate(res.begin(),res.end(),0);
    }
};
#endif //P9_P135_分发糖果_H
