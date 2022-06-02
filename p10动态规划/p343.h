//
// Created by 肖应雄 on 2022/6/2.
//

#ifndef P10_P343_H
#define P10_P343_H

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return --n;
        vector<int> index(n+1,0);
        index[0] = 1;
        index[1] = 1;
        index[2] = 2;
        index[3] = 3;
        for (int i = 4; i <= n; ++i) {
            int max = 0;
            for (int j = 2; j < i; ++j) {
                if (max < (j * index[i-j]))
                    max = j * index[i-j];
            }
            index[i] = max;
        }
        return index.back();
    }
};
#endif //P10_P343_H
