#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>



class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        backtracking(nums,0);
        std::sort(nums.begin(), nums.end());
        return res;
    }

    void backtracking(vector<int> &nums,int index){
        if (index > nums.size())
            return;
        if (std::find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }

        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return;
    }
};


int main() {
    string s("0123");
    int i = atoi(s.c_str());
    cout << i << endl;
}
