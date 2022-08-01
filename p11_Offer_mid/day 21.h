//
// Created by xm on 2022/8/1.
//

#ifndef P11_OFFER_MID_DAY_21_H
#define P11_OFFER_MID_DAY_21_H
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1)
                ++ count;
            n = n >> 1;
        }
        return count;
    }
};

class Solution {
public:
    // 算法核心 每次求进位的数
    int add(int a, int b) {
        while (b != 0) {
            int temp = a ^ b;  // 不进位
            int tem =(unsigned int) (a & b) << 1;  // 进位
            a = temp;
            b = tem;
        }
        return a;
    }
};
#endif //P11_OFFER_MID_DAY_21_H
