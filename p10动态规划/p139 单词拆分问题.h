//
// Created by xm on 2022/6/24.
//

#ifndef P10_P139_单词拆分问题_H
#define P10_P139_单词拆分问题_H
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> bind(s.size()+1,0);
        bind[0] = 1;
        for (int i = 1; i < bind.size(); ++i) {
            for (const auto &item : wordDict) {
                if (i >= item.size() && bind[i-item.size()] == 1) {
                    string str(s.begin()+i-item.size(),s.begin()+i);
                    if (str == item)
                        bind[i] = 1;
                }
            }
        }
        return bind.back() == 1 ? true: false;
    }
};

#endif //P10_P139_单词拆分问题_H
