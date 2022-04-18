#include <iostream>
using namespace std;
#include <vector>
#include <numeric>


class Solution {
public:
    vector<pair<int,int>> path;
    vector<vector<pair<int,int>>> res;

    vector<string> letterCombinations(string digits) {
        vector<int> digit;
        for (const auto &item : digits)
            digit.push_back(item - '0');
        trackbacking(digit,0);


        for (const auto &item : res)
        {
            for (const auto &item : item)
                cout << item.first << ":" << item.second<< ",";
            cout << endl;
        }
        return vector<string>();
    }
    /*
     * 2:1,3:1,
        2:1,0:2,
        2:1,0:3,
     */
    // index 从0开始
    void trackbacking(vector<int> digit,int index){
        if (path.size() == digit.size()){
            res.push_back(path);
        }
        for (int i = index; i < digit.size(); ++i) {
            for (int j = 1; j < 4; ++j) {
                path.push_back(pair<int,int> {digit[index],j});
                trackbacking(digit,++index);
                path.pop_back();
            }
            if (index == 9){
                path.push_back(pair<int,int>{digit[index],4});
                trackbacking(digit,++index);
                path.pop_back();
            }
        }
        return;
    }
};


int main() {
    Solution solution;
    solution.letterCombinations("23");

    return 0;
}
