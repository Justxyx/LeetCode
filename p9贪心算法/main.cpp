#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
ostream& operator<<(ostream &os,const vector<int> v){
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << ",";
    }
    return os;
}




int main() {
    string s = "ababcbacadefegdehijhklij";
    Solution solution;
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    solution.merge(v);
}
