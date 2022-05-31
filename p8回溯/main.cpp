#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>
#include <set>


class Solution {
public:
    int len = 10;
    vector<vector<char>> res;
    void solveSudoku(vector<vector<char>>& board) {

        backtracking(board,0,0,9);
        board = res;
        return;
    }

    void backtracking(vector<vector<char>> &borad,int x,int y,int n){
        if (x == n-1 && y == n)
            res = borad;
        if (x > 8)
            return;
        if (y > 8)
            return;

        for (int i = x; i < n; ++i) {
            for (int j = y; j <n ; ++j) {
                if (borad[i][j] != '.')
                    continue;
                else{

                    for (int k = 1; k < len; ++k) {
                        //条件判断
                        char val = k + '0';
                        if (isTrue(borad,i,j,n,val)){
                            borad[i][j] = val;
                            if ((j+1) == n)
                                backtracking(borad,i+1,0,n);
                            else
                                backtracking(borad,i,j+1,n);
                        } else{
                            continue;
                        }

                    }
                }
            }
        }


    }
    bool isTrue(vector<vector<char>> &borad,int x,int y,int n,char val){
        // 只能在行出现一次
        for (int i = 0; i < n; ++i) {
            if (borad[x][i] == val)
                return false;
        }
        // 列只能出现一次
        for (int i = 0; i < n; ++i) {
            if (borad[i][y] == val)
                return false;
        }
        // 9宫格内只出现一次
        int x_3 = x/3 * 3; // 0  1  2
        int y_3 = y/3 * 3;

        for (int i = x_3; i < x_3 +3; ++i) {
            for (int j = y_3; j <y_3 +3 ; ++j) {
                if (borad[i][j] == val)
                    return false;
            }
        }
        return true;
    }

};


int main() {


    char cs = '1';
    int i = cs - '0';
    cout << i << endl;

    int s = 9;
    char cc = s + '0';
    cout << cc << endl;


    cout << 6/3 * 3 << endl;

}
