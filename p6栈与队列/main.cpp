#include <iostream>
#include <stack>
using namespace std;
#include <queue>
#include <list>


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        list<int> list;
        vector<int> vector;
        int count = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if ((i+1 < nums.size()) && nums[i] == nums[i+1]){
                ++count;
                continue;
            } else{

            }
        }
    }
};



int main() {


}
