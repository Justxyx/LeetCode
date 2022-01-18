#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <string>




int main() {
    Solution s;
    vector<string> v = {"bella","label","roller"};
    vector<string> v2 =  s.commonChars(v);
    for (const auto &item : v2)
        cout << item << endl;


    return 0;
}
