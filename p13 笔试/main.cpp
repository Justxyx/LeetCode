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

vector<int> swapAdjacent(vector<int> array) {
    if (array.empty())
        return array;
    int i = 1;
    while (i < array.size()) {
        swap(array[i-1],array[i]);
        i += 2;
    }
    return array;
}

string countVotes11(vector<string> validCandidates, vector<string> voteCasted) {
    string str = "";
    if (voteCasted.empty()) {
        for (const auto &item : validCandidates) {
            cout << item << "=" << 0;
            cout << " ";
        }
        cout << "invalidVotes"<< "=" << 0 << " " << "Winner=N/A";
    }

    vector<int> dp(validCandidates.size(), 0);
    int sum_vote = 0;
    for (int i = 0; i < validCandidates.size(); ++i) {
        for (const auto &item : voteCasted) {
            if (validCandidates[i] == item) {
                ++dp[i];
                ++sum_vote;
            }
        }
    }
    int invalidVotes = voteCasted.size() - sum_vote;
    int max_vote = 0;
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] > dp[max_vote])
            max_vote = i;
    }
    string winer = "";
    if (invalidVotes > dp[max_vote])
        winer = "N/A";
    else
        winer = validCandidates[max_vote];

    string res = "";
    for (int i = 0; i < validCandidates.size(); ++i) {
        res += validCandidates[i] + "=" + to_string(dp[i]) +
         " " ;
//        cout << validCandidates[i] << "=" << dp[i];
//        cout << " " << "invalidVotes=" << invalidVotes << " "
//        << "Winner="<<  winer << endl;
    }
    res += "invalidVotes=" + to_string(invalidVotes) + " "
           + "Winner=" +  winer;

    return res;
}


string RemoveLetters(string s, vector<char> letters) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < letters.size(); ++j) {
            if (s[i] == letters[j]) {
                s[i] = '%';
                continue;
            }
        }
    }

    int left = 0;
    int right = 0;
    while (right < s.size()) {
        if (s[right] != '%') {
            swap(s[left], s[right]);
            ++ left;
            ++ right;
        } else {
            ++ right;
        }
    }
    s.resize(left);
    return s;
}


string countVotes(vector<string> validCandidates, vector<string> voteCasted) {

    vector<int> dp(validCandidates.size(), 0);
    int sum_vote = 0;
    for (int i = 0; i < validCandidates.size(); ++i) {
        for (const auto &item : voteCasted) {
            if (validCandidates[i] == item) {
                ++dp[i];
                ++sum_vote;
            }
        }
    }
    int invalidVotes = voteCasted.size() - sum_vote;
    int max_vote = 0;
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] > dp[max_vote])
            max_vote = i;
    }
    string winer = "";
    if (voteCasted.size() == 0)
        winer = "N/A";
    else if (invalidVotes > dp[max_vote])
        winer = "N/A";
    else
        winer = validCandidates[max_vote];

    string res = "";
    for (int i = 0; i < validCandidates.size(); ++i) {
        res += validCandidates[i] + "=" + to_string(dp[i]) +
               " " ;
    }
    res += "invalidVotes=" + to_string(invalidVotes) + " "
           + "Winner=" +  winer;

    return res;
}


// 可以引入的库和版本相关请参考 “环境说明”
#include <iostream>
#include <string>
using namespace std;

// 本题已设置测试用例
// 如有需要，请按你的实际需求修改参数和返回值类型

   class LaneNode {
    public:
      std::string node_id;
      std::vector<LaneNode*> next_lanes;
   };

void doDFS(LaneNode *root, vector<vector<string>> res, vector<string> path) {
    if (root->next_lanes.empty()) {
        res.push_back(path);
        return;
    }
    for (const auto &item : root->next_lanes) {
        path.push_back(item->node_id);
        doDFS(item, res, path);
        path.pop_back();
    }
    return;
}

std::vector<std::vector<std::string>> solution(std::vector<LaneNode*> root_lanes)
{
    // 在这⾥写代码
    vector<vector<string>> res;
    vector<string> path;
    for (const auto &item : root_lanes) {
        path.push_back(item->node_id);
        doDFS(item,res, path);
        path.pop_back();
    }
    return res;
}

int solution(int N) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    vector<int> v;
    while (N > 0)  {
        int temp = N % 10;
        v.push_back(temp);
        N /= 10;
    }
    std::reverse(v.begin(), v.end());
    int temp = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 5 && i+1 < v.size()) {
            temp = i;
            if (v[i] > )
        }
    }
}


int main() {
    int N = 123000;
    vector<int> v;
    while (N > 0)  {
        int temp = N % 10;
        v.push_back(temp);
        N /= 10;
    }
    std::reverse(v.begin(), v.end());
    for (const auto &item : v) {
        cout << item << endl;
    }
}