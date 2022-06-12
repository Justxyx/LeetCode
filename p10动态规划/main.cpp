#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>


class Solution {
public:

    int count_int(vector<int> &v,int res){
        int count = 0;
        for (const auto &item : v){
            if (item == res)
                ++ count;
        }
        return count;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if ( sum < target)
            return 0;
        int right = (sum + target) / 2;

        int count = 0;

        vector<int> bind(sum+1,0);
        bind[0] = 1;
        if (right == 0)
            ++ count;
        for (const auto &item : nums) {
            for (int i = 0; i < bind.size(); ++i) {
                if (bind[i] == 1 && bind[i+item] == 0) {
                    bind[item + i] = -1;
                    if ((item + i) == right) {
                        count += count_int(nums,item);
                    }
                }
            }
            bind[item] = 1;
            if (item == right)
                ++ count;
            for (auto &item : bind) {
                if (item == -1)
                 item = 1;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> v{1,1,1,1,1};
    cout <<  solution.findTargetSumWays(v,3);
    return 0;
}

