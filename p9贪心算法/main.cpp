#include <iostream>
using namespace std;
#include <vector>
#include <numeric>



/*
 * 寻找每一跳能到的最远距离
 */


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        while ( k > nums.size()){
            k -= 2;
        }

        std::sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (k <= 0)
                break;
            if (nums[i] < 0){
                nums[i] = -nums[i];
                --k;
            } else{
                break;
            }
        }

        if (k > 0 && k%2 == 1 ){
            if (nums[i] > nums[i-1])
                nums[i-1] = -nums[i-1];
            else
                nums[i] = -nums[i];
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};

int main() {
    Solution solution;
    vector<int> v{-8,3,-5,-3,-5,-2};
    solution.largestSumAfterKNegations(v,6);
}
