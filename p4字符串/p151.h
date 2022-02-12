//
// Created by 肖应雄 on 2022/2/12.
//

#ifndef P4_P151_H
#define P4_P151_H

/**
 * 结题思路：
 *  我能不能说这题我写了两个小时？其实解题思路跟答案是一样的
 *  1. 算出多余空格个数
 *  2. 缩进 去掉尾巴多余空格数
 *  3. 交换字母
 *  4. 交换每个单词的顺序
 *
 *  程序写完，第一步计算多余空格数总是有bug。边界问题呀，兄弟。
 *  还是代码写的太少了。
 */


/**
 * p 151
 * 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。

 */



class Solution {
public:
    string reverseWords(string s) {



        int moreSpace = 0;
        // 1. 统计多余空格个数
        int left = 0,right = s.size() - 1;
        while (s[left++] == ' ')
            ++moreSpace;
        while (s[right--] == ' ')
            ++moreSpace;
        while (left < right){
            if (s[left] == ' ' && s[left+1] == ' ')
                ++moreSpace;
            ++ left;

        }



//        cout << moreSpace << endl;
        // 2.缩进
        left = 0;
        right = 0;
        while ( s[right] == ' '){
            ++ right;
        }
        while (right < s.size()){

            if (s[right] == ' ' && s[right+1] == ' '){
                ++ right;
            } else{
                swap(s[left],s[right]);
                ++ left;
                ++ right;
            }

        }
        cout << "缩进后的字符串：" << s << endl;

        // 3. 统计尾巴空格个数
        int i = 0;
        for (i = 0; i < s.size() - 1; ++i) {
            if (s[i] == ' ' && s[i+1] == ' '){
                break;
            }
            if (s[i] == ' ' && s[i+1] == '\0'){
                break;
            }

        }
        if ( i == s.size() - 1 ){
            ++ i;
        }

        cout << "字符串长度为："<< i << endl;  // 空格个数
        cout << "尾巴空格个数:"<< s.size() - i << endl;
        cout << "morespce:" << moreSpace << endl;

        // 4. swap
        left = 0;
        int len = s.size() - moreSpace;
        right = len - 1;
        while (left < right){
            swap(s[left],s[right]);
            ++ left;
            -- right;
        }
        s.resize(len);
        cout << s << endl;

        // 5. 将每个单词翻转
        left = 0;
        right = 0;
        int x,y;
        while (right < s.size()){
            if (s[right+1] != ' ' && s[right+1] != '\0'){
                right ++;
                continue;
            }

            // swap3
            x = left;
            y = right;
            while (x < y){
                swap(s[x],s[y]);
                ++x;
                --y;
            }
            right++;
            left = right + 1;
        }
        cout << s << endl;



        return s;
    }
};

#endif //P4_P151_H
