//
// Created by 肖应雄 on 2022/5/28.
//

#ifndef P10_P509_H
#define P10_P509_H

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int p1 = 0;
        int p2 = 1;
        int p = 0;
        for (int i = 2; i <= n; ++i) {
            p = p1 + p2;
            p1 = p2;
            p2 = p;
        }
        return p;
    }
};
#endif //P10_P509_H
