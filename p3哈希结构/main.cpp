#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>



vector<int> method(){
    vector<int> v{2,3,4};
    return v;
}


int main() {
    Solution solution;
    vector<int> v{1,1,1};
    vector<vector<int>> res;
    res = solution.threeSum(v);
    for (const auto &item1 : res){
        for (const auto &item : item1)
            cout << item << "," ;
        cout << endl;
    }





    return 0;
}
