//
// Created by 肖应雄 on 2022/4/15.
//


class Solution {
private:
    const string letterMap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
public:
    vector<string> result;
    string s;
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0)
            return result;
        backtracking(digits,0);
        return result;
    }

    void backtracking(const string &digits,int index){
        if (index == digits.size()){
            result.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); ++i) {
            s.push_back(letter[i]);
            backtracking(digits,index + 1);
            s.pop_back();
        }
    }
};