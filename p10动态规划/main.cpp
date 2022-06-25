#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cmath>


int main() {
    vector<int> v{1,2};
    cout << *max_element(v.begin(),v.begin()+2);
    Solution solution;
//    cout << solution.rob(v) << endl;
    return 0;
}

