#include <iostream>
using namespace std;
#include <vector>
#include <list>

/**
 * 四数之和，要求四个数字不相同
 * 1     2   3   4   5   6   7   8
 * i     j   left                right
 */


//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        std::sort(nums.begin(), nums.end());
//        vector<vector<int>> v;
//        int left,right;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (i>0 && nums[i] == nums[i-1] )
//                continue;
//            left = i + 1;
//            right = nums.size() - 1;
//            while (left < right){
//                if (nums[i] + nums[left] + nums[right] > 0){
//                    -- right;
//                } else if ( nums[i] + nums[left] + nums[right] < 0){
//                    ++left;
//                } else{
//                    v.push_back({nums[i],nums[left],nums[right]});
//                    while (left< right && nums[left] == nums[left+1])
//                        left ++ ;
//                    while (left< right && nums[right] == nums[right-1])
//                        right--;
//                    ++left;
//                    --right;
//                }
//            }
//        }
//        return v;
//    }
//}



int main() {
    Solution solution;
//    vector<int> v{2,2,2,2,2};
    vector<int> v{0,0,0,0,0};
    solution.fourSum(v,0);
}
