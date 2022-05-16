#include <iostream>
using namespace std;
#include <vector>
//#include <numeric>
#include <algorithm>


ostream& operator<<(ostream &os,const vector<vector<int>> res){
    for (const auto &item : res){
        os << "[" << item[0] << "," << item[1] << "]" << ",";
    }
    return os;
}


int main() {
    vector<int> v1{1,0,2};
    vector<int> v2{3,4,5,1,2};
    vector<vector<int>> v{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
    Solution solution;
    cout << solution.reconstructQueue(v) << endl;
    cout << v << endl;

//    vector<int> res{1,2,3};
//    res.insert(res.begin()+1,12);
//    for (const auto &item : res)
//        cout << item << endl;
}
