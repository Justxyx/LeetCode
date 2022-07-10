#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        int count = 0;
        while ( begin < end) {
             mid = (begin+end)/2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                end = mid;
            else
                begin = mid + 1;
        }
        if (nums[mid] != target)
            return 0;
        else {
            int i = 0;
            while ( mid - i >= 0 && nums[mid-i] == target)
            {
                ++ count;
                ++ i;
            }
            i = 1;
            while (nums[mid+i] == target) {
                ++ count;
                ++ i;
            }
        }
        return count;
    }
};


int main() {
    vector<int> v{2, 2};
    Solution solution;
    cout << solution.search(v, 2);
}