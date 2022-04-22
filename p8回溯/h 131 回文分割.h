//
// Created by 肖应雄 on 2022/4/22.
//

#ifndef P8_H_131_回文分割_H
#define P8_H_131_回文分割_H

class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return res;
    }

    void backtracking(string &s,int startIndex ){
        if (startIndex >= s.size()){
            res.push_back(path);
        }

        for (int i = startIndex; i < s.size(); ++i) {
            string s1(s.begin()+startIndex,s.begin()+i+1);
            if (isBack(s1)){
                // s1 是回文串
                path.push_back(s1);
                backtracking(s,i + 1);
                path.pop_back();
            } else{
                continue;
            }
        }

    }

    bool isBack(string s){
        bool b = true;
        if (s.size() == 0){
            return false;
        }
        auto p1 = s.begin();
        auto p2 = s.end();
        --p2;
        while ( p1 < p2){
            if (*p1 != *p2)
                b = false;
            ++p1;
            --p2;
        }
        return b;
    }
};

#endif //P8_H_131_回文分割_H
