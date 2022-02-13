//
// Created by 肖应雄 on 2022/2/13.
//

#ifndef P4_OFFER51_H
#define P4_OFFER51_H

/**
 * offer 51
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 */

/**
 * 解题思路1  有额外空间
// */
//class Solution {
//public:
//    string reverseLeftWords(string s, int n) {
//        vector<char> s1(s.begin() + n ,s.end());
//        vector<char> s2(s.begin(),s.begin() + n);
//        string s3 = string(s1.begin(),s1.end());
//        string s4 = string(s2.begin(),s2.end());
//        cout << s3 + s4 << endl;
//        return s3+s4;
//        }
//};


/**
 * 解题思路二：
 *      局部翻转加整体翻转
 */
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        cout << s << endl;
        return s;
    }
};
#endif //P4_OFFER51_H
