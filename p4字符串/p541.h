#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>


/**
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 */

class Solution {
public:

    void swap2(int i,int j,vector<char> &v){
        while ( i < j){
            swap(v[i],v[j]);
            ++i;
            --j;
        }
    }
    string reverseStr(string s, int k) {
        vector<char> v(s.begin(),s.end());

        int count = 0;
        while (v.size() >= (count + 2*k)){
            // 翻转 count ～ count+k-1
            swap2(count,count+k -1,v);
            count += 2*k;
        }

//        处理剩余部分
        int res = v.size() - count;
        if (res >= k){
            swap2(count,count+k -1,v);
        } else if ( res > 0){
            swap2(count,v.size() -1,v);
        }
        for (const auto &item : v)
            cout << item << endl;
        string s1(v.begin(),v.end());
//        cout << s1 << endl;

        return s1;
    }
};

