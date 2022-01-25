//
// Created by 肖应雄 on 2022/1/25.
//

#ifndef P3_P383_H
#define P3_P383_H

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for (int i = 0; i < magazine.size(); ++i) {
//            cout <<  magazine[i] - 'a' << endl;
            v[(magazine[i] - 'a')] ++;
        }
//        for (const auto &item : v)
//            cout << item << endl;
        for (int i = 0; i < ransomNote.size(); ++i) {
            v[(ransomNote[i] - 'a')] -- ;
            if (v[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};

#endif //P3_P383_H
