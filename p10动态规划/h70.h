//
// Created by 肖应雄 on 2022/5/29.
//

#ifndef P10_H70_H
#define P10_H70_H
/*\
 * 回溯算法时间复杂度超时
 */
class Solution {
public:
    int count = 0;
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 2;
        if (n < 3)
            return n;
        int f = 0;
        for (int i = 3; i <= n; ++i) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
};
#endif //P10_H70_H
