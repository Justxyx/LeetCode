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
#include <unordered_set>
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



class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param sentences string字符串
     * @return int整型
     */
    int cal_words_num(string sentences) {
        // write code here
        int count = 0;
        int i = 0;
        while (i < sentences.size()) {
            if (sentences[i] != ' ') {
                ++ count;
                while (sentences[i] != ' ' && i < sentences.size()) {
                    ++ i;
                }
            }
            ++ i;
        }
        return count;
    }
};
/*
 * ["A", "3", "2", "大王", "4"]
 */
class Solution2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断是否为顺子
     * @param cards string字符串vector 随机抽中的5张牌
     * @return bool布尔型
     */
    bool is_straight(vector<string>& cards) {
        // write code here
        // 1-10 11 J 12 Q 13 K 14 x 15 d
        vector<int> index(16, 0);
        for (auto &item : cards) {
            if (item == "A")
                    index[1] = 1;
            else if (item == "2")
                index[2] = 1;
            else if (item == "3")
                index[3] = 1;
            else if (item == "4")
                index[4] = 1;
            else if (item == "5")
                index[5] = 1;
            else if (item == "6")
                index[6] = 1;
            else if (item == "7")
                index[7] = 1;
            else if (item == "8")
                index[8] = 1;
            else if (item == "9")
                index[9] = 1;
            else if (item == "10")
                index[10] = 1;
            else if (item == "J")
                index[11] = 1;
            else if (item == "Q")
                index[12] = 1;
            else if (item == "K")
                index[13] = 1;
            else if (item == "小王")
                index[14] = 1;
            else if (item == "大王")
                index[15] = 1;
            else
                index[0] = 1;
        }

        int bio = 0;
        if (index[14] == 1)
            ++ bio;
        if (index[15] == 1)
            ++ bio;

        int count = 0;
        for (int i = 1; i < index.size(); ++i) {
            if (index[i] == 1)
                ++ count;
            else if (count != 0 && bio != 0) {
                -- bio;
                ++ count;
            } else if (count == 0) {
                continue;
            } else {
                -- count;
            }

            if (count == 5)
                return true;
        }
        return false;
    }
};




void solution(vector<int> &v, int k) {
    std::sort(v.begin(), v.end());
    int count = 0;
    double sum = 0;
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        count = 0;
        sum = 0;
        int mins = INT_MAX;
        for (int j = i; j < v.size(); ++j) {
            sum += v[j];
            ++ count;
            mins = min(mins, v[j]);
            if ((sum/count) > k * mins) {
                res = max(res, count-1);
                break;
            }
        }
    }
    cout << res << endl;
    return;
}

// 3 2 2
//int main() {
//    int n, k;
//    cin >> n;
//    cin >> k;
//    vector<int> v(n, 0);
//    for (int i = 0; i < n; ++i) {
//        int temp = 0;
//        cin >> temp;
//        v[i] = temp;
//    }
//    solution(v, k);
//    return 0;
//}






int main() {
    // 'A'   65    '1' 49
    Solution solution;
    cout << solution.showDown("SA HA C4 S4 H5 S6");

}