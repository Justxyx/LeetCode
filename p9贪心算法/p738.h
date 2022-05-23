//
// Created by 肖应雄 on 2022/5/23.
//

#ifndef P9_P738_H
#define P9_P738_H
/*
 *
主要思想：

1. 多位数 n123  是否大于  nnnn
2. 小于 减一位 999
3. 等于  nnnn
4. 大于  {
    1. 除第一位外 后几位是否是单调递增 是 直接返回
    2. 不是 第二位-1  后面9999
}
 */

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int res_n = n;
        if (n < 10)
            return n;
        vector<int> index;  // 123 -> 321
        while (n > 0){
            int s = n % 10;
            index.push_back(s);
            n = n/10;
        }
        reverse(index.begin(),index.end());
        // 1.等于
        int b = true;
        for (int i = 0; i < index.size(); ++i) {
            if (index[i] == index[0])
                continue;
            else{
                b = false;
                break;
            }
        }
        if (b)
            return res_n;
        // 2. 小于
        b = true;
        for (int i = 1; i < index.size(); ++i) {
            if (index[i] == index[0])
                continue;
            if (index[i] > index[0]){
                b = false;
                break;
            } else{
                b = true;
                break;
            }
        }
        if (b){
            int size = index.size();
            int res = 0;
//            if (index[1] == 0){
//                -- size;
//                while (size > 0){
//                    res += 9 * pow(10,size - 1);
//                    --size;
//                }
//            } else{
            res += (index[0]-1) * pow(10,--size);
            while (size > 0){
                res += 9 * pow(10,--size);
//                }
            }
            return res;
        }
        // 3. 大于
        // 3.1判断递增
        b = true;
        int pre = index[1];
        int i = 0;
        for (i = 2; i < index.size(); ++i) {
            if (index[i] >= pre){
                pre = index[i];
                continue;
            } else{
                b = false;
                break;
            }
        }
        if (b)
            return res_n;
        // 3.2 非递增
        i = i - 1;
        while (index[i] == index[i-1])
            -- i;
        index[i] = --index[i];
        for (int j = i+1; j < index.size(); ++j) {
            index[j] = 9;
        }
        int size = index.size();
        int res = 0;
        for (int j = 0; j < index.size(); ++j) {
            res += index[j] * pow(10,--size);
        }
        return  res;
    }
};

#endif //P9_P738_H
