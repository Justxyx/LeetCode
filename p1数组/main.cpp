#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
//#include "p724.h"

// p209
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int min = 0;
        int sum = nums[i];
        while (j < nums.size()){

            if (sum >= target){
                if (min == 0){
                    min = j - i + 1;
                } else{
                    if (min > (j - i + 1)){
                        min = j - i + 1;
                    }
                }
                if ( i < j ) {
                    sum = sum - nums[i ++];
                } else
                {
                    if (j == nums.size()-1)
                        break;
                    sum = sum + nums[++j];
                }
            } else  {
                if (j == nums.size()-1)
                    break;
                sum = sum + nums[++j];

            }
        }
        return min;
    }
};


int main() {
    int nums[] = {5,1,3,5,10,7,4,9,2,8};
    int target = 15;
    vector<int> cost(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    auto a = solution.minSubArrayLen(target,cost);
    cout << a << endl;
}
