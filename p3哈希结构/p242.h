//
// Created by 肖应雄 on 2022/1/18.
//

#ifndef P3_P242_H
#define P3_P242_H

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for (int i = 0; i < s.length(); ++i) {
            v[(s[i] - 'a')]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            v[(t[i] - 'a')]--;
        }
        for (const auto &item : v)
            if ( item != 0)
                return false;
        return true;
    }
};

#endif //P3_P242_H
