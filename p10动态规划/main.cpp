#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 1 : 0;
        }
        unordered_set<int> r_set, b_set;
        int sum = 0;
        r_set.insert(-nums[0]);
        r_set.insert(nums[0]);
        if (nums[0] == target)
            ++ sum;
        if (nums[0] == -target)
            ++ sum;
        for (int i = 1; i < nums.size(); ++i) {

            for (const auto &i2: r_set) {
                int right = i2 + nums[i];
                int left = i2 - nums[i];
                if (right == target) {
                    ++sum;
                }
                if (left == target) {
                    ++sum;
                }
                b_set.insert(left);
                b_set.insert(right);
            }
            r_set.insert(b_set.begin(), b_set.end());
            b_set.clear();
        }

        return sum;
    }
};

int main() {
    vector<int> v{1,1,1,1,1};
    Solution solution;
    cout << solution.findTargetSumWays(v,3);
    return 0;
}

