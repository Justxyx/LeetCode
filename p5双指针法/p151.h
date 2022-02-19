//
// Created by 肖应雄 on 2022/2/20.
//

#ifndef P5_P151_H
#define P5_P151_H

/**
 * p 151
 * 这题写过的  第二次解题明显比第一次快
 * 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。
 */

/**
 * 输入：s = "the sky is blue"
 *输出："blue is sky the"
 */


class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return s;

        //去空格
        int s1 = 0 ,s2 = 0;
        while (s[s2] == ' ')
            ++ s2;
        while (s2 < s.size()){
            if (s[s2] != ' '){
                swap(s[s1++],s[s2++]);
            } else if (s[s2 +1] != ' '){
                swap(s[s1++],s[s2++]);
            } else{
                ++ s2;
            }
        }
        int size = s.size();
        s2 = size - 1;
        while (s[s2] == ' '){
            -- s2;
            -- size;
        }
        s.resize(size);
//        cout << s << endl;
//        return s;
        int start = 0;
        int end = s.size() - 1;

        while (start < end){
            swap(s[start++],s[end--]);
        }

        start = 0;
        end = 0;
        int p1,p2;
        while (end <= s.size()){
            if (s[end] != ' ' && s[end] != '\0'){
                ++ end;
                continue;
            }
            p1 = start;
            p2 = end-1;
            while (p1 < p2){
                swap(s[p1++],s[p2--]);
            }
            ++ end;
            start = end;
        }

        cout << s << endl;
        return s;
    }
};

#endif //P5_P151_H
