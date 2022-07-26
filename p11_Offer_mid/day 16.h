//
// Created by xm on 2022/7/26.
//

#ifndef P11_OFFER_MID_DAY_16_H
#define P11_OFFER_MID_DAY_16_H
;
class Solution45 {
public:
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), comp);
        string res = "";
        for (const auto &item : nums) {
            res += to_string(item);
        }
        return res;
    }
    static bool comp(int a, int b) {
        if ( a == b)
            return a;
        string s_a = to_string(a);
        string s_b = to_string(b);
        return s_a + s_b < s_b + s_a;
    }

};


class Solution61 {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> bind(14, 0);
        for (const auto &item : nums) {
            ++bind[item];
        }
        int count_ss = bind[0];
        int i = 1;
        while (bind[i] == 0) {
            ++ i;
        }
        if ((i-count_ss) > 9)
            return false;
        for (int j = 1; j < bind.size(); ++j) {
            if (bind[j] > 1)
                return false;
        }
        auto begins = bind.begin()+i;
        int sum = 0;
        if (i+5 > 14)
            sum = accumulate(begins, bind.end(),0);
        else
            sum = accumulate(begins, bind.begin()+i+5, 0);
        if (sum + count_ss < 5)
            return false;
        return true;
    }
}
#endif //P11_OFFER_MID_DAY_16_H
