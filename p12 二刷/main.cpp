#include <iostream>
#include <vector>
using namespace std;
#include <numeric>
#include "vector.h"

// 1. 组合问题  其核心思想 for 循环横向遍历 递归纵向遍历
class Solution77 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
    void backtracking(int n, int k, int index) {
        if (path.size() == k)
            res.push_back(path);

        for (int i = index; i <= n; ++i) {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }

};
class Solution216 {

public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }
    void backtracking(int k, int n, int index) {
        if (path.size() == k && accumulate(path.begin(), path.end(), 0) == n)
            res.push_back(path);
        if (path.size() >= k)
            return;
        for (int i = index; i < 10; ++i) {
            path.push_back(i);
            backtracking(k, n, i+1);
            path.pop_back();
        }
        return;
    }
};
/*
 * 这道题目第一次刷的时候就没搞明白 第二次刷用时超久  还要看
 */
class Solution17 {

public:
    vector<char> path;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return res;
        vector<int> digit;
        for (const auto &item : digits)
            digit.push_back(item-48);
        backtracking(digit, 0);
        return res;
    }

    void backtracking(vector<int> digit, int index_i) {
        if (path.size() == digit.size())
            res.push_back(string(path.begin(), path.end()));
        if (path.size() >= digit.size())
            return;


        for (int j = 0; j <=3 ; ++j) {

            if (j == 3) {
                if (digit[index_i] == 7){

                } else if (digit[index_i] == 9){

                } else
                    continue;
            }



            if (digit[index_i] == 8)
                path.push_back((digit[index_i]-2)*3 + 98+j);
            else if (digit[index_i] == 9)
                path.push_back((digit[index_i]-2)*3 + 98+j);
            else
                path.push_back((digit[index_i]-2)*3 + 97+j);
            backtracking(digit, index_i+1);
            path.pop_back();
        }

        return;
    }

};
// 允许重复问题
class Solution39 {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
    void backtracking(vector<int> &bind, int target, int index) {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == target)
            res.push_back(path);
        if (sum >= target)
            return;

        for (int i = index; i < bind.size(); ++i) {
            path.push_back(bind[i]);
            backtracking(bind, target, i);
            path.pop_back();
        }
        return;
    }
};
// 组合去重
class Solution40 {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
    void backtracking(vector<int> &bind, int target, int index) {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == target)
            res.push_back(path);
        if (sum >= target)
            return;

        for (int i = index; i < bind.size(); ++i) {
            if (i > index && bind[i] == bind[i-1])
                continue;
            path.push_back(bind[i]);
            backtracking(bind, target, i + 1);
            path.pop_back();
        }
        return;
    }
};


int main() {
    return 0;
}
