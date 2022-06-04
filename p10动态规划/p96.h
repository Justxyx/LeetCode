//
// Created by 肖应雄 on 2022/6/4.
//

#ifndef P10_P96_H
#define P10_P96_H

class Solution {
public:
    int numTrees(int n) {
        vector<int> bind(n+1,0);
        if (n <= 2)
            return n;
        bind[0] = 1;
        bind[1] = 1;
        bind[2] = 2;
        int left = 0;
        int right = 0;
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            // left
            for (int j = 0; j < i; ++j) {
                left = j;
                right = i - 1 - j;
                sum += bind[left] * bind[right];
            }
            bind[i] = sum;
            sum = 0;
        }
        return bind.back();
    }
};
#endif //P10_P96_H
