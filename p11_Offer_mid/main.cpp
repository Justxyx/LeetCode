#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while (begin < end) {
            mid = (begin+end)/2;
            if (nums[mid] == mid)
                begin = mid+1;
             else
                 end = mid;
        }
        while (mid < nums.size() && nums[mid] == mid)
            ++ mid;
        return mid;
    }
};



int main() {
    vector<int> v{1, 4};
    Solution solution;
}