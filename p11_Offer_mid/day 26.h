//
// Created by xm on 2022/8/4.
//

#ifndef P11_OFFER_MID_DAY_26_H
#define P11_OFFER_MID_DAY_26_H

class Solution {
public:
    int strToInt(string str) {
        vector<char> path;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ')
                continue;
            if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
                path.push_back(str[i]);
                for (int j = i+1; j < str.size(); ++j) {
                    if (str[j]>= '0' && str[j] <= '9')
                        path.push_back(str[j]);
                    else
                        break;
                }
            }
            break;
        }
        if (path.empty())
            return 0;
        bool b = false;
        string s(path.begin(), path.end());
        if (s[0] == '+' || s[0] =='-') {
            if (s[0] == '-')
                b = true;
            s = string(path.begin()+1, path.end());
        }
        if (s.empty())
            return 0;
        cout << s << endl;

        long res = 0;
        for (const auto &item : s) {
            res = 10 * res + (item-48);
            if (res > INT_MAX)
            {
                if (b)
                    return INT_MIN;
                return INT_MAX;
            }
        }
        if (b)
            res = -res;
        return res;
    }
};

#endif //P11_OFFER_MID_DAY_26_H
