//
// Created by xm on 2022/8/20.
//

#ifndef P13__P1_微软_8_19_H
#define P13__P1_微软_8_19_H
int solution(vector<int> &X, vector<int> &Y, int W) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    if (X.empty())
        return 0;
    std::sort(X.begin(), X.end());
    int res = 1;
    int left = X[0];
    int right = W + left;
    for (int i = 0; i < X.size(); ++i) {
        if (X[i] >= left && X[i] <= right)
            continue;
        else {
            ++ res;
            left = X[i];
            right = left + W;
        }
    }
    return res;
}


bool comp(char a, char b) {
    return a > b;
}
string solution(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    vector<char> v;
    for (const auto &item : S) {
        v.push_back(item);
    }
    string res_str = "";
    if (v.size() == 1)
        return res_str + v[0];
    std::sort(v.begin(), v.end(), comp);
    char max_alone = -1;
    int i = 0;
    vector<char> res;
    while ( i + 1 < v.size()) {
        if (res.empty() && v[i] == '0')
            break;
        if (v[i] == v[i+1]) {
            res.push_back(v[i]);
            i += 2;
        } else {
            max_alone = max(max_alone, v[i]);
            ++ i;
        }
    }
    for (int j = 0; j < res.size(); ++j) {
        res_str += res[j];
    }
    if (max_alone != -1)
        res_str += max_alone;
    else if (i+1 == v.size())
        res_str += v.back();
    int temp_size = res.size();
    for (int j = temp_size-1; j >= 0; --j) {
        res_str += res[j];
    }
    if (res_str.empty())
        return "0";
    return res_str;
}


/*
 * 无向图  A不出来
 */
int solution(vector<int> &A, vector<int> &B) {


}
#endif //P13__P1_微软_8_19_H
