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




int main() {
//    Solution solution;
//    Point p1(1,1);
//    Point p2(2,2);
//    Point p3(1,3);
//    Point p4(0,2);
//    solution.getArea(p1, p2, p3, p4);

    int n;
    while (cin >> n) {
        vector<int> gym(n);
        vector<int> work(n);
        for (int i = 0; i < n; i++) cin >> work[i];
        for (int i = 0; i < n; i++) cin >> gym[i];
        int result = 0;

        // 处理逻辑

        cout << result << endl;
    }
    return 0;
};