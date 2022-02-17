//
// Created by 肖应雄 on 2022/2/17.
//

#ifndef P5_P344_H
#define P5_P344_H


class Solution {
public:
    void reverseString(vector<char>& s) {
        int b = 0;
        int e = s.size() ;
        if (e==0)
            return;
        --e;
        while (b < e){
            swap(s[b],s[e]);
            ++b;
            --e;
        }
        return;
    }
};
#endif //P5_P344_H
