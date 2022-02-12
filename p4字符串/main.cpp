#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

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
// s = "the  sky is bluee"

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
            if (s[right] == ' ' && s[right-1] == ' ')
                ++ moreSpace;
            ++ left;
            -- right;
        }

        if (s[left] == ' ' && s[right] == ' '){
            if (moreSpace)
                --moreSpace;
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


int main() {
    Solution solution;
//    solution.reverseWords("a      a");
    solution.reverseWords("the sky is blue");

    return 0;
}
