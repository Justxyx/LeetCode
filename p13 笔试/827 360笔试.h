//
// Created by xm on 2022/8/27.
//

#ifndef P13__827_360笔试_H
#define P13__827_360笔试_H

set<char> sets = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
void solution3601(string &str) {
    int i = 0;
    int j = str.size() - 1;
    while (i <= j) {
        if (str[i] == str[j] && sets.find(str[i]) != sets.end()) {
            ++ i;
            -- j;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

/*
 * 4
1 2 3 4
4 3 2 1
2 2 2 1
0 2 0 1
 */

void solution3602(vector<vector<int>> &v) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res = 0;
        // 4
        res += v[i][3];
        // 3
        while (v[i][2] > 0 && v[i][0] > 0) {
            res += 1;
            --v[i][2];
            --v[i][0];
        }
        // 2
        while (v[i][1] > 0) {
            if (v[i][1] > 1) {
                ++ res;
                v[i][1] -= 2;
                continue;
            }
            if (v[i][1] == 1 && v[i][0] > 1) {
                ++res;
                --v[i][1];
                v[i][0] -= 2;
            } else {
                break;
            }
        }
        // 1
        while (v[i][0] > 3) {
            ++ res;
            v[i][0] -= 4;
        }
        cout << res << endl;
    }
    return;
}

int main() {
    int n;
    cin >> n ;
    vector<vector<int>> v (n, vector<int>(4, 0));
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> temp;
            v[i][j] = temp;
        }
    }
    solution3602(v);
    return 0;
}
#endif //P13__827_360笔试_H
