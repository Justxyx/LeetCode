#include <iostream>
using namespace std;
#include <vector>


// 704
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0,e = nums.size() - 1;
        int mid;
        while ( b <= e){
            mid = (e - b)/2 + b;
            if ( nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                e = mid -1;
            else
                b = mid + 1;
        }
        return -1;
    }
};
void test704(){
    int nums[]= {5};
    int target = 5;
    vector<int> cost(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    cout << solution.search(cost,target) << endl;
}


int main() {
    test704();
    return 0;
}
