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



/*
 * 15
82 79 86 86 89 42 97 89 92 86 78 42 100 100 100
 */
// A-Z 65 - 90   ' ' -> 32
void solution1(vector<int> &v) {
    int min_v = *min_element(v.begin(), v.end());
    int max_v = *max_element(v.begin(), v.end());

    if ((max_v - min_v) > 58 || min_v < 32 || max_v < 32) {   //无解
        cout << 0 << endl;
        return;
    }
    if ((max_v - min_v) > 25) {   // 一定存在空格  最小的那个数即为空格
        int dump = min_v - 32;
        string str = "";
        for (const auto &item : v) {
            str += (char)(item-dump);
        }
        cout << str << endl;
    } else if (max_v == min_v) {  // 所有数字都相等
        if (max_v >= 90) {
            cout << 27 << endl;
        } else if (max_v >=65 && max_v <= 90) {
            cout << max_v-65 + 2 << endl;
        } else{
            string str = "";
            for (int i = 0; i < v.size(); ++i) {
                str += " ";
            }
            cout << str << endl;
        }
    } else {  // 没有空格
        if (min_v > 65)
            cout << min_v - 65 + 1 << endl;
        else if (min_v == 65) {
            string str = "";
            for (const auto &item : v) {
                str += (char)item;
            }
            cout << str << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return;
}
//int main() {
//    int n;
//    cin >> n;
//    vector<int> v(n, 0);
//    for (int i = 0; i < n; ++i) {
//        int temp;
//        cin >> temp;
//        v[i] = temp;
//    }
////    vector<int> v{82,79,86,42};
//    solution1(v);
////    int a = 65;
////    cout << (char)a << endl;
//}
bool judge(string &str) {
    for (const auto &item : str) {
        if ((item >= '0' && item <= '9') || (item >= 'A' && item <= 'F') )
            continue;
        return false;
    }
    return true;
}


void solution2(vector<string> &v) {
    unordered_map<char, string> maps;

    maps.insert(make_pair('R', "FF0000"));
    maps.insert(make_pair('G', "FFC932"));
    maps.insert(make_pair('B', "0000FF"));
    maps.insert(make_pair('K', "000000"));
    maps.insert(make_pair('Y', "FFFF00"));
    maps.insert(make_pair('W', "FFFFFF"));
    maps.insert(make_pair('P', "FF88FF"));
    for (const auto &item : v) {
        stack<string> stacks;
        int i = 0;
        vector<pair<string, string>> res;
        while (i < item.size()) {
            if ((item[i] == '#') && ((i+1) < item.size())) {
                if (maps.find(item[i+1]) != maps.end()) {  // 存在map中
                    stacks.push(maps[item[i+1]]);
                    ++ i;
                } else if (item[i+1] == 'C' && (i+7) < item.size()) {  // 自定义
                    string str(item.begin()+i+2, item.begin()+i+7);
                    if (judge(str)) {   // 是16进制数
                        stacks.push(str);
                        i += 7;
                    }
                }
            }
            ++ i;
        }
    }
    cout << "hey" << endl;
    return;
}

//int main() {
//    int n;
//    cin >> n;
//    vector<string> v;
//    for (int i = 0; i < n; ++i) {
//        string str;
//        cin >> str;
//        v.push_back(str);
//    }
//    solution2(v);
//}


//int main() {
//    int W, H;
//    cin >> W >> H;   // 地图长宽
//    int N;
//    cin >> N;      // 食物数量
//    vector<vector<int>> rice(N, vector<int>(3,0));  // 食物坐标
//    for (int i = 0; i < N; ++i) {
//        int x, y, t;
//        cin >> x >> y >> t;
//        vector<int> v{x,y,t};
//        rice[i] = v;
//    }
//    int M;
//    cin >> M;
//    vector<vector<int>> fire(M, vector<int>(3,0));
//    for (int i = 0; i < M; ++i) {
//        int a,b,c;
//        cin >> a >> b >> c;
//        vector<int> v{a,b,c};
//        fire[i] = v;
//    }
////    cout << "end" << endl;
//    return 0;
//}


int main() {
    int m,n;
    cin >> m >> n;
    int s_point;
    cin >> s_point;
    vector<pair<int, int>> v(s_point, make_pair(0, 0));
    for (int i = 0; i < s_point; ++i) {
        string str;
        cin >> str;
        int s = 0;
        string str_x = "", str_y = "";
        for (s = 0; s < str.size(); ++s) {
            if (str[s] == ',')
                break;
            str_x += str[s];
        }
        ++ s;
        for (; s < str.size(); ++s) {
            if (str[s] == ',')
                break;
            str_y += str[s];
        }
        v[i] = make_pair(atoi(str_x.c_str()), atoi(str_y.c_str()));
    }
    int s_test;
    cin >> s_test;
    vector<pair<int, int>> v_test(s_test, make_pair(0, 0));
    for (int i = 0; i < s_test; ++i) {
        string str;
        cin >> str;
        int s = 0;
        string str_x = "", str_y = "";
        for (s = 0; s < str.size(); ++s) {
            if (str[s] == ',')
                break;
            str_x += str[s];
        }
        ++ s;
        for (; s < str.size(); ++s) {
            if (str[s] == ',')
                break;
            str_y += str[s];
        }
        v_test[i] = make_pair(atoi(str_x.c_str()), atoi(str_y.c_str()));
    }


    vector<vector<int>> grap(m, vector<int>(n, 0));
    for (const auto &item : v) {
        grap[item.first][item.second] = 1;
    }


    for (int i = 0; i < grap.size(); ++i) {
        for (int j = 0; j < grap[0].size(); ++j) {
            if (grap[i][j] == 1) {
                grap[i][j] = 2;   // 2 为起点
            }
        }
    }

}

bool DFS(vector<vector<int>> &grap) {

}