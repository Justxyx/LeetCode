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
#include <unordered_map>
#include <string>
#include <sstream>
// 数组
int main1(){
    int a;
    vector<int> vec;
    while(cin >> a) {
        vec.push_back(a);
        if(getchar() == '\n') break;//关键
    }
    return 0;
}

/*
 *         a,c,bb
        f,dddd
        nowcoder
 */
int main2(){
    string str;
    while(getline(cin, str)){
        vector<string> vec;
        stringstream ss(str);
        string ele;
        while(getline(ss, ele, ',')){
            vec.push_back(ele);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size() - 1; i++) cout << vec[i] << ',';
        cout << vec[vec.size() - 1] << endl;
    }
    return 0;
}

 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};





int main() {
    string str = "10010";
}