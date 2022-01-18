//
// Created by 肖应雄 on 2022/1/18.
//

#ifndef P3_P1002_H
#define P3_P1002_H

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26,0);
        int count = 0;
        for (const auto &item : words){
            vector<int> v2(26,0);
            for (int i = 0; i < item.length(); ++i) {
                v2[(item[i]) - 'a'] ++;
            }
            if (count == 0){
                for (int i = 0; i < 26; ++i) {
                    v[i] += v2[i];
                }
            } else{
                for (int i = 0; i < 26; ++i) {
                    if (v[i] > v2[i]){
                        v[i] = v2[i];
                    }
                }
            }
            ++ count;
        }
        for (const auto &item : v)
            cout << item << endl;
        cout << " ------------- " << endl;
        vector<string> s;
        for (int i = 0; i < v.size(); ++i) {
            while ( v[i] --){
                string str(1,i + 'a');
                s.push_back(str);
            }
        }
        cout << s.size() << endl;
        return s;
    }
};

#endif //P3_P1002_H
