#include <iostream>
using namespace std;
#include <vector>

#include <iostream>
//#include<bits/stdc++.h>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <queue>
#include <numeric>
#include <stack>
#include <unordered_set>



/*
 *     int n;
    cin >> n;
    vector<int> v1(n,0);
    vector<int> v2(n,0);
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        cin >> temp;
        v1[i] = temp;
    }
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        cin >> temp;
        v2[i] = temp;
    }
 */

void solution1(string &A, string &B) {
    if (A < B)
        cout << -1 << endl;
    else if (A == B)
        cout << 0 << endl;
    else
        cout << -1 << endl;
    return;
}

//int main() {
//    string A, B;
//    cin >> A;
//    cin >> B;
//    solution1(A, B);
//
//}

void solution() {

}


int main() {
    deque<char> v;
    string str;
    int n;
    cin >> str;
    cin >> n;


    if (str.empty() || n < 0) {
        cout << "" << endl;
    }
    for (const auto &item : str) {
        if (item == ',')
            continue;
        else
            v.push_back(item);
    }
    while (n > v.size())
        n -= v.size();
    for (int i = 0; i < n; ++i) {
        int temp = v.back();
        v.pop_back();
        v.push_front(temp);
    }
    auto p = v.begin();
    str = "";
    while (p != v.end()) {
        str += *p;
        str += ",";
        ++p;
    }
    str.resize(str.size()-1);
    cout << str << endl;
    return 0;
}

int main3() {
    string str;
    cin >> str;
    int left = 0, right = str.size()-1;
    while (left < right) {
        swap(str[left], str[right]);
        ++ left;
        -- right;
    }
    cout << str << endl;
    return 0;
}

int main1() {
    cout << strcmp("hello", "he");
}

void solution(string &A, string &B) {
    if (A < B)
        cout << -1 << endl;
    else if (A == B)
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return;
}
