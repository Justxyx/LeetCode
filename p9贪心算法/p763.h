//
// Created by 肖应雄 on 2022/5/22.
//

#ifndef P9_P763_H
#define P9_P763_H

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> index(27,0);
        for (const auto &item : s){
            ++index[item - '0' - 48];
        }
        int count = 0;
        vector<int> v(27,0);
        for (const auto &item : s){
            ++ count;
            // 1. 标记
            if (v[item - '0' - 48] == 0)
                v[item - '0' - 48] = 1;
            // 2. 判断
            if (index[item - '0' - 48] == 1){
                v[item - '0' - 48] = 0;
            } else{
                -- index[item - '0' - 48];
            }
            // 3. 计算count
            if (accumulate(v.begin(),v.end(),0) == 0){
                res.push_back(count);
                count = 0;
            }
        }
        cout << res << endl;
        return res;
    }
};
#endif //P9_P763_H
