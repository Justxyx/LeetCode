//
// Created by xm on 2022/7/8.
//

#ifndef P11_OFFER_MID_DAY3_H
#define P11_OFFER_MID_DAY3_H
// p05
class Solution {
public:
    string replaceSpace(string s) {
        vector<char> v;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ')
                v.push_back(s[i]);
            else
            {
                v.push_back('%');
                v.push_back('2');
                v.push_back('0');
            }
        }
        return string(v.begin(), v.end());
    }
};
// p58
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reserve(s, 0, s.size() - 1);
        reserve(s, 0, s.size()-n-1);
        reserve(s, s.size()-n, s.size()-1);



        return s;
    }

    void reserve(string &s, int begin, int end) {
        while (begin <= end) {
            std::swap(s[begin],s[end]);
            ++begin;
            --end;
        }
    }
};
#endif //P11_OFFER_MID_DAY3_H
