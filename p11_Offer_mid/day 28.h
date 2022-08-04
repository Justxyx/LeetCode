//
// Created by xm on 2022/8/4.
//

#ifndef P11_OFFER_MID_DAY_28_H
#define P11_OFFER_MID_DAY_28_H

class Solution {
public:
    vector<string> res;
    vector<char> path;
    int size;
    vector<string> permutation(string s) {
        if (s.empty())
            return res;
        std::sort(s.begin(), s.end());
        size = s.size();
        backtracking(s);
        return res;
    }

    void backtracking(string s) {

        if (path.size() == size) {
            res.push_back(string(path.begin(), path.end()));
            return;
        }
        if (s.empty())
            return;

        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i-1])
                continue;
            path.push_back(s[i]);
            backtracking(string(s.begin(),s.begin()+i) + string(s.begin()+i+1, s.end()));
            path.pop_back();
        }
        return;
    }


};
#endif //P11_OFFER_MID_DAY_28_H
