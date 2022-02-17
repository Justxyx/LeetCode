//
// Created by 肖应雄 on 2022/2/17.
//

#ifndef P4_KMP_H
#define P4_KMP_H
/**
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle
 * 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 */

/**
 *  KMP 算法思想：
 *      aabaabaaf
 *      aabaaf
 *      名词解释：
 *          1. 前缀 ： 不包含最后一个字母
 *          2. 后缀 ： 不包含第一个字母
 *          **最长相等前后缀**
 *          **前后缀都是从左往右读**  ** 后缀也是的**
 *
 *          前缀：
 *          a       0
 *          aa      1
 *          aab     前： a ab   后：b ba    0
 *          aaba    前： a aa aab 后： a ba aba 1
 *          aabaa   前： a aa aab aaba 后： a aa baa abaa 2
 *          aabaaf  0
 *
 *          后缀：
 *          f
 *          fa
 *          faa
 *          faab
 *          faaba
 *
 *
 *      待匹配字符串，比如说在f这里发生了不匹配，就要看f的前一位，看f的前一位最长相等前后缀，直接跳转到这一位就ok
 *      所以问题就是 如何求解next数组
 */

/**
 * "mississippi"
    "issip"


 */

class Solution {
public:


    int countNext(string str){
        string s_pre;
        string s_end;
        int max = 0;
        bool flag = 0;
        for (int i = 1; i < str.size(); ++i) {
            // 前缀
            s_pre = string(str.begin(),str.begin()+i);
            // 后缀
            s_end = string(str.end() - i ,str.end());
//        cout << "当前的i值为：" << i << "前缀为：" <<s_pre << ". 后缀为：" << s_end << endl;
            if (s_pre == s_end){
                max = i;
            }
        }
//    cout << max << endl;
        return max;
    }

/**
 * 原始求next数组的方法
 */
//    vector<int> next(const string str){
//        vector<int> v(str.size(),0);
//
//
//        string s_cur;
//        for (int i = 1; i < str.size(); ++i) {
//            // 当前值
//            s_cur = string(str.begin(),str.begin()  + i);
////        cout << "当前值为：" << s_cur << endl;
//            int j = countNext(s_cur);
//            v[i-1] = j;
//        }
//        return v;
//    }

    vector<int> next(const string str){
        vector<int> v(str.size(),0);
        int j = -1;
        v[0] = j;
        for(int i = 1; i < str.size(); i++) { // 注意i从1开始
            while (j >= 0 && str[i] != str[j + 1]) { // 前后缀不相同了
                j = v[j]; // 向前回退
            }
            if (str[i] == str[j + 1]) { // 找到相同的前后缀
                j++;
            }
            v[i] = j; // 将j（前缀的长度）赋给next[i]
        }
        for ( auto &item : v)
            ++ item;
        return v;
    }



    int strStr(string haystack, string needle) {

        if (haystack == needle){
            return 0;
        }
        if (needle.size() == 0){
            return 0;
        }
        vector<int> v(needle.size(),0);
        v = next(needle);
        // 输出next数组
        cout << "next 数组：";
        for (const auto &item : v)
            cout << item << ",";
        cout << endl;
        int j = 0;  // needle 基准指针
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i] == needle[j]){
                ++ j;
            } else if (j == 0){
                j = 0;
            } else
            {
                cout << "j的原始值为：" << j << endl;
                j = v[j - 1] ;
                --i;
//                cout << "经过next数组调整后，j的值为：" << j << endl;
//                cout << "经过next数组调整后，i的值为：" << i << endl;
//                cout << "字符串haystack为：" << string(haystack.begin(),haystack.begin() + i) << endl;
//                cout << "字符串needle为：" << string(needle.begin(),needle.begin() + j) << endl;
            }
            if (j >= needle.size()){
                return ( i - needle.size() + 1);
            }
        }
        return -1;

    }
};


#endif //P4_KMP_H
