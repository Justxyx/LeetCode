#include <iostream>
using namespace std;
#include <vector>
//#include "p724.h"


int main() {
    int nums[] = {3,2,2,3};
    int target = 3;
    vector<int> cost(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    cout << solution.removeElement(cost, target) << endl;
}
