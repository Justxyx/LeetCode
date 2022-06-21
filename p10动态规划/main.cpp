#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (*min_element(nums.begin(),nums.end()) > target || target == 0)
            return 0;
        vector<int> res(target+1,0);
        res[0] = 1;

        for (int i = 1; i < res.size(); ++i) {
            for (const auto &item : nums) {
                if ((i - item) >= 0 && res[i - item] != 0) {
                    if (res[i-item]  > INT_MAX - res[i])
                        continue;

                    res[i] += res[i-item];
                }
            }
        }
        return res.back();
    }
};
int main() {
    vector<int> v{1,2,3};
    Solution solution;
    cout << solution.combinationSum4(v,4);

    return 0;
}

