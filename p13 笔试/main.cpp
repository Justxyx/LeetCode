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




#include <iostream>
#include <vector>

using namespace std;

void trans_8(vector<int> &bind, int n) {
    bind[0] = (1 & n) >> 0;
    bind[1] = (2 & n) >> 1;
    bind[2] = (4 & n) >> 2;
    bind[3] = (8 & n)>> 3;
    bind[4] = (16 & n) >> 4;
    bind[5] = (32 & n) >> 5;
    bind[6] = (64 & n) >> 6;
    bind[7] = (128 & n) >> 7;
    return;
}
int GetFarthestRoad(vector<uint8_t>& vecRoad)
{
    // todo
    // 转换
    vector<vector<int>> bind(vecRoad.size(), vector<int>(8, 0));
    for (int i = 0; i < vecRoad.size(); ++i) {
        trans_8(bind[i], vecRoad[i]);
    }
    vector<int> temp(8, 0);
    int count = 0;
    for (int i = 0; i < bind.size(); ++i) {
        if (i == 0) {

        } else {
            temp = bind[i];
            for (int j = 0; j < 8; ++j) {
                bind[i][j] = bind[i][j] | bind[i-1][j];
            }

            for (int j = 0; j < 8; ++j) {
                if (temp[j] == 1)
                    continue;
                else if (temp[j] == 0 && bind[i][j] == 0)
                    continue;
                else {
                    bind[i][j] = -1;
                }
            }

            for (int j = 1; j < 8; ++j) {
                if (bind[i][j] == -1 && bind[i][j-1] == 0 )
                    bind[i][j] = 0;
            }
            for (int j = 6; j >= 0; --j) {
                if (bind[i][j] == -1 && bind[i][j+1] == 0) {
                    bind[i][j] = 0;
                }
            }
            for (int j = 0; j < 8; ++j) {
                if (bind[i][j] == -1)
                    bind[i][j] = 1;
            }
        }

        if (accumulate(bind[i].begin(), bind[i].end(), 0) == 8)
            break;
        else
            ++ count;
    }
    return count;
}


class Solutionxx {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param m int整型 水池容量
     * @param t int整型 总时长
     * @param m1 int整型 进水阀打开时每分钟进水量
     * @param t1 int整型 进水阀开关切换时长
     * @param m2 int整型 排水阀打开时每分钟排水量
     * @param t2 int整型 排水阀开关切换时长
     * @return int整型
     */
//    cout << solution1.ComputeRemanentWater(10,10,4,5,2,5);

    int ComputeRemanentWater(int m, int t, int m1, int t1, int m2, int t2) {
        // write code here
        bool start = 1;
        bool stop = 1;
        int sum = 0;
        int start_time = 0;
        int stop_time = 0;
        for (int i = 1; i <= t; ++i) {
            if (start) {
                sum += m1;
                ++ start_time;
            } else {
                ++ start_time;
            }
            if (stop) {
                sum -= m2;
                ++ stop_time;
            } else {
                ++ stop_time;
            }
            if (sum > m)
                sum = m;
            if (sum < 0)
                sum = 0;
            if (start_time == t1) {
                start_time = 0;
                bool temp = start;
                start = !temp;
            }
            if (stop_time == t2) {
                stop_time = 0;
                bool temp = stop;
                stop = !temp;
            }
        }
        return sum;
    }
};
//int main() {
//    Solution solution1;
//    cout << solution1.ComputeRemanentWater(10,3,4,1,2,1);
//    return 0;
//}

/*
 * 1.0,1.0
5.5,1.0
6.0,3.5
 */

//
//int main() {
//    int m , n;
//    cin >> m;
//    cin >> n;
//    int res = 1;
//    for (int i = 1; i < min(m, n); ++i) {
//        if ((m % i) == 0 && (n % i) == 0)
//            res = i;
//    }
//    cout << res << endl;
//    return 0;
//}

/*
 *  5 4
    4 9 6 7 8    0- 8    5 - 13
// */
//int main() {
//    int n, x;
//    cin >> n;
//    cin >> x;
//    vector<int> v(n, 0);
//    for (int i = 0; i < n; ++i) {
//        int temp = 0;
//        cin >> temp;
//        v[i] = temp;
//    }
//    int left = v[0] - x;
//    int right = v[0] + x;
//    int count = 0;
//    for (int i = 1; i < n; ++i) {
//        int cur_left = v[i] - x;
//        int cur_right = v[i] + x;
//        if ((cur_left >= left && cur_left <= right) || (cur_right >= left && cur_right <= right) || (cur_left <= left && cur_right >= right)) {
//            left = max(left, cur_left);
//            right = min(right, cur_right);
//            continue;
//        }
//        ++ count;
//        left = v[i] - x;
//        right = v[i] + x;
//    }
//    cout << count;
//    return 0;
//}
class Ants {
public:
    double antsCollision(int n) {
        // write code here
        double s = pow(0.5, n);
        return 1.0 - 2 *  s;
    }
};
 // 0 1 0 1 0 0 0 0

class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        // write code here
        AB[0] += AB[1];
        AB[1] = AB[0] - AB[1];
        AB[0] -= AB[1];
        return AB;
    }
};

// [[1,3],[1,2],[1,1],[3],[2],[3]]
class Solution1111 {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        // write code here
        stack<int> stacks;
        deque<int> que;
        vector<int> res;
        for (const auto &item : op) {
            if (item[0] == 1) {
                stacks.push(item[1]);
                if (que.empty())
                    que.push_back(item[1]);
                else if (que.back() >= item[1])
                    que.push_back(item[1]);
            } else if (item[0] == 3) {
                res.push_back(que.back());
            } else {
                int temp = stacks.top();
                stacks.pop();
                if (que.back() == temp)
                    que.pop_back();
            }
        }
        return res;
    }
};

class Solutionxxxxx {

public:
    /**
     *
     * @param a int整型
     * @param op char字符型
     * @param b int整型
     * @return int整型
     */

    int calc(int a, char op, int b) {
        // write code here
        if (op == '+')
            return a + b;
        if (op == '*')
            return a*b;
        if (op == '/')
            return a/b;
        if (op == '-')
            return a-b;
        return 0;
    }
};



//int main() {
//    string str;
//    cin >> str;
//    // 255 255 255 255
//    vector<int> bind;
//    string temp = "";
//    for (const auto &item : str) {
//        if (item != '.')
//            temp += item;
//        else {
//            bind.push_back(atoi(str.c_str()));
//            temp = "";
//        }
//    }
//    for (const auto &item : bind) {
//        if (item < 0 || item > 255)
//            cout << "False" << endl;
//    }
////    string str = "00123";
////    int i = atoi(str.c_str());
////    cout << i << endl;
//    cout << "True" << endl;
//    return 0;
//}


//int main() {
//    string str;
//    while(getline(cin, str)){
//        vector<string> vec;
//        stringstream ss(str);
//        string ele;
//        while(getline(ss, ele, ',')){
//            vec.push_back(ele);
//        }
////        sort(vec.begin(), vec.end());
////        for(int i = 0; i < vec.size() - 1; i++) cout << vec[i] << ',';
////        cout << vec[vec.size() - 1] << endl;
//
//        vector<double> vecs;
//        for (const auto &item : vec) {
//            vecs.push_back(atof(item.c_str()));
//        }
//
//    }
//
////    string s = "1.2";
////    double i = atof(s.c_str());
////    cout << i << endl;
//    return 0;
//}


int k_sy(int k, int num) {
    int res = 0;
    int index = 0;
    while (num != 0) {
        res += (pow(k, index++) * (num % 10));
        num /= 10;
    }
    return res;
}
/*
 * 3 7 3 8
222
222
 */
int main_1() {
    int len1, k1, len2 , k2;
    cin >> len1;
    cin >> k1;
    cin >> len2;
    cin >> k2;
    int num1, num2;
    cin >> num1;
    cin >> num2;

    num1 = k_sy(k1, num1);
    num2 = k_sy(k2, num2);
    if (num1 == num2)
        cout << "=";
    if (num1 < num2)
        cout << "<";
    if (num1 > num2)
        cout << ">";
    return 0;
}

/*
 * 5 6
1 2 3
2 3 4
3 4 5
4 5 6
1 5 1
2 4 2
 */
int main_2() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> grap(n+1, vector<int>(n+1, -1));


    vector<vector<int>> res(n+1, vector<int>(n+1, INT_MAX));

    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x;
        cin >> y;
        cin >> w;

        grap[x][y] = w;
    }

    for (int i = 1; i <+ n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (grap[i][j] != -1) {
                for (int k = 1; k <= n; ++k) {
                    if (grap[j][k] != -1) {
                        int s = pow((grap[i][j]+ grap[j][k]), 2);
                        res[i][k] = min(res[i][k], s);
                    }
                }
            }
        }
    }

    return 0;
}


int mainxxxx() {
    int n;
    cin >> n;
    vector<int> bind(n, 0);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        bind[i] = temp;
    }

    int max_left = 0;
    int max_right = 0;
    int p1, p2, p3, p4;

    p1 = 0;
    p2 = 1;
    max_left = bind[p1] + bind[p2];
    int res = INT_MIN;
    while (p2 < n) {

    }
}



class Solution11111 {
public:

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param arr int整型一维数组
     * @param arrLen int arr数组长度
     * @return bool布尔型
     */
    bool validate(int* arr, int arrLen) {
        // write code here
        vector<int> v(arrLen, 0);
        for (int i = 0; i < arrLen; ++i) {
            v[i] = arr[i];
        }

        if (v.size() < 3) {
            if (v[0] == 5 && v[1] == 5)
                return true;
            else
                return false;
        }

        int left = 0, mid = 1, right = 2;
        while (right < v.size()) {
            mid = right - 1;
            left = mid - 1;
            if (v[left] == 5 && v[right] == 5)
                return true;
            if (v[mid] == 5 ) {
                if (v[left] == 5 || v[right] == 5)
                    return true;
            }
            ++ right;
        }
        return false;
    }
};

/*
 *
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 10进制转2进制
     * @param val int整型 十进制数字
     * @return long长整型
     */
    long long decimalToBinary(int val) {
        // write code here
        vector<int> res;
        while (val >= 1) {
            if (val % 2 == 0)
                res.push_back(0);
            else
                res.push_back(1);
            val /= 2;
        }
        long long result = 0;
        for (int i = res.size()-1; i >= 0; --i) {
            result = result * 10 + res[i];
        }
        return result;
    }
};

int main() {

}


