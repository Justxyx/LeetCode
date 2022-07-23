#include <iostream>
#include <vector>
using namespace std;
#include <numeric>
#include <set>
#include <list>
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


// 2. 分割问题
// 这道题想了好久
class Solution131 {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
    void backtracking(string s, int index) {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        if (index >= s.size())
            return;
        for (int i = index; i < s.size(); ++i) {
            string ss = string(s.begin()+index, s.begin()+i+1);
            if (isPart(ss)) {
                cout << ss << endl;
                path.push_back(ss);
                backtracking(s, i+1);
                path.pop_back();
            }
        }
    }
    bool isPart(string str) {
        int begin = 0;
        int end = str.size() - 1;
        bool b = true;
        while (begin <= end) {
            if (str[begin] != str[end])
                b = false;
            ++ begin;
            -- end;
        }
        return b;
    }
};
// 跟上一题差不多 都是分割问题
class Solution93 {
public:
    vector<string> path;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return res;
    }
    void backtracking(string s, int index) {
        if (index == s.size() && path.size() == 4)
        {
            string path_res = "";
            for (const auto &item : path) {
                path_res += item;
                path_res += ".";
            }
            path_res.resize(path_res.size()-1);
            res.push_back(path_res);
        }
        for (int i = index; i < s.size(); ++i) {

            if (path.size() >= 4)
                return;
            string ss(s.begin()+index, s.begin()+i+1);
            int ss_int = atoi(ss.c_str());
            if ((ss.size() == 1) || (ss[0] != '0' && ss_int < 256 && ss.size() < 4)) {
                cout << ss_int << endl;
                path.push_back(ss);
                backtracking(s, i+1);
                path.pop_back();
            }
        }
        return;
    }
};


// 3.子集问题
class Solution78 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int> &nums, int index) {
        if (index >= nums.size())
            return;
        res.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }

};
// 子集去重复
class Solution90 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int> &nums, int index) {
        res.push_back(path);
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i-1] == nums[i])
                continue;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
};
/*
 * 这题目有空再看看  非递增的序列 子集去重问题 用set
 */
class Solution491 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int> &nums, int index) {
        set<int> sets;
        if (path.size() >= 2)
            res.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            if (true) {
                if (sets.find(nums[i]) == sets.end()) {
                    sets.insert(nums[i]);
                } else {
                    continue;
                }
            }
            if (path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                backtracking(nums, i+1);
                path.pop_back();
            }
        }
    }
};


//4. 排列问题
// 排列问题就一个思想 画图！！！！！！！！！！！！！！！
class Solution46 {
public:
    vector<int> path;
    vector<vector<int>> res;
    int size = 0;
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        backtracking(nums, -1);
        return res;
    }
    void backtracking(vector<int> nums, int value) {
        if (path.size() == size)
            res.push_back(path);
        if (path.size() > size)
            return;
        if (value >= 0)
            nums.erase(nums.begin() + value);
        for (int i = 0; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i);
            path.pop_back();
        }
    }
};
class Solution47 {
public:
    vector<int> path;
    vector<vector<int>> res;
    int path_size = 0;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> bind(nums.size(), 0);
        path_size = nums.size();
        std::sort(nums.begin(), nums.end());
        backtracking(nums, bind);
        return res;
    }
    void backtracking(vector<int> &nums, vector<int> &bind) {
        if (path.size() == path_size)
            res.push_back(path);
        if (path.size() > path_size)
            return;
        set<int> back;
        for (int i = 0; i < nums.size(); ++i) {
            if (back.find(nums[i]) != back.end())
                continue;
            if (bind[i])
                continue;
            back.insert(nums[i]);
            path.push_back(nums[i]);
            bind[i] = 1;
            backtracking(nums, bind);
            path.pop_back();
            bind[i] = 0;
        }
        return;
    }

};


class Solution51 {
public:
    int count = 0;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> bind(n, vector<int> (n, 0));
        vector<int> used(n, 0);
        backtracking(bind, 0, used);
        vector<vector<string>> vec = res;
        return res;
    }

    void backtracking(vector<vector<int>> &bind, int index, vector<int> &used) {

        if (index == bind.size()) {
            if ( judge(bind)) {
                ++ count;
                processBind(bind);
            }
            return;
        }

        for (int i = 0; i < bind.size(); ++i) {
            if (used[i])
                continue;
            bind[index][i] = 1;
            used[i] = 1;
            backtracking(bind, index + 1, used);
            bind[index][i] = 0;
            used[i] = 0;
        }
    }

    void processBind(vector<vector<int>> &bind) {
        vector<string> vec;
        for (int i = 0; i < bind.size(); ++i) {
            string s = "";
            for (int j = 0; j < bind.size(); ++j) {
                if (bind[i][j] == 0)
                    s+='.';
                else
                    s+='Q';
            }
            vec.push_back(s);
        }
        res.push_back(vec);
    }


    bool judge(vector<vector<int>> &bind) {
        for (int i = 0; i < bind.size(); ++i) {
            for (int j = 0; j < bind.size(); ++j) {
                if (bind[i][j] == 1) {
                    int x = i, y = j;
                    while (++x < bind.size() && ++y < bind.size()) {
                        if (bind[x][y] == 1)
                            return false;
                    }
                    x = i, y = j;
                    while (++x < bind.size() && --y >= 0)
                        if (bind[x][y] == 1)
                            return false;
                }
            }
        }
        return true;
    }

};


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> bind_x(9,vector<int>(10,0));  // 横排
        vector<vector<int>> bind_y(9,vector<int>(10,0));  // 竖排
        vector<vector<int>> bind_9(9,vector<int>(10,0));  // 九宫格
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    bind_x[i][board[i][j] - 48] = 1;
                    bind_y[j][board[i][j] - 48] = 1;
                    int box = (i/3) * 3 + (j/3);
                    bind_9[box][board[i][j] - 48] = 1;
                }
            }
        }
        backtracking(bind_x, bind_y, bind_9, board, 0, 0);
        cout << "hey" << endl;
    }

    void backtracking(vector<vector<int>> &bind_x, vector<vector<int>> &bind_y, vector<vector<int>> &bind_9, vector<vector<char>> &board, int x, int y) {
        if (x == 9)
            return;

        for (int i = x; i < 9; ++i) {
            for (int j = y; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k < 10; ++k) {
                        cout << "i" << i  << "j" << j << "k"  << k << endl;
                        int box = (i/3) * 3 + (j/3);
                        if (bind_x[i][k] != 1 && bind_y[j][k] != 1 && bind_9[box][k] != 1) {
                            if (k == 8) {
                                cout << "h" << endl;
                            }
                            board[i][j] = k + 48;
                            bind_x[i][k] = 1 ;
                            bind_y[j][k] = 1 ;
                            bind_9[box][k] = 1;
                            int s = i;
                            int z = j;
                            if (z == 8) {
                                s++;
                                z = 0;
                            } else
                                ++ z;
                            backtracking(bind_x,bind_y,bind_9,board,s,z);
                            bind_x[i][k] = 0 ;
                            bind_y[j][k] = 0 ;
                            bind_9[box][k] = 0;
                        } else{
                            continue;
                        }
                    }
                }
            }
        }
        return;
    }

};

int main() {
    Solution solution;
    vector<vector<char>> v{{'5','3','.','.','7','.','.','.','.'},
                           {'6','.','.','1','9','5','.','.','.'},
                           {'.','9','8','.','.','.','.','6','.'},
                           {'8','.','.','.','6','.','.','.','3'},
                           {'4','.','.','8','.','3','.','.','1'},
                           {'7','.','.','.','2','.','.','.','6'},
                           {'.','6','.','.','.','.','2','8','.'},
                           {'.','.','.','4','1','9','.','.','5'},
                           {'.','.','.','.','8','.','.','7','9'}};

    solution.solveSudoku(v);
    return 0;
}
