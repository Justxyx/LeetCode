#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>





int main() {

    vector<int> a = {4,9,5};
    vector<int> b = {9,4,9,8,4};
    Solution s;
    vector<int> ab =  s.intersection(a,b);
    for (const auto &item : ab)
        cout << item << endl;


    return 0;
}
