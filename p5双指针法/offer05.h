//
// Created by 肖应雄 on 2022/2/18.
//

#ifndef P5_OFFER05_H
#define P5_OFFER05_H

/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */

/**
 * 思路：
 *      这个题目在之前写过一次，用vector做的
 *      现在用双指针来写
 *      1. 查找空格个数
 *      2. 扩充数组
 *      3. 双指针 从后往前
 */

class Solution {
public:
    string replaceSpace(string s) {
        int size = s.size();
        if (s.size() == 0)
            return "";
        int spaceCount = 0;
        for (const auto &item : s){
            if (item == ' ')
                ++ spaceCount;
        }

        s.resize(s.size() + 2*spaceCount);
//        cout << "s的长度为：" << s.size() << endl;
        int p1 = s.size() - 1;
        int p2 = size - 1;
        while (p2 >= 0){
            if (s[p2] != ' '){
                swap(s[p2--],s[p1--]);
            } else{
                s[p1--] = '0';
                s[p1--] = '2';
                s[p1--] = '%';
                -- p2;
            }
        }
        cout << s << endl;
        return s;
    }
};

#endif //P5_OFFER05_H
