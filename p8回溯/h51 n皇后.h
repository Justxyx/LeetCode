//
// Created by 肖应雄 on 2022/4/28.
//

#ifndef P8_H51_N皇后_H
#define P8_H51_N皇后_H
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> isQue(n,vector<int>(n,0));
        backtracking(n,0,isQue);
        return res;
    }
    void backtracking(int n,int row,vector<vector<int>> &isQue){
        if (path.size() == n){
            res.push_back(path);
            return;
        }
        if (row >= n)
            return;


        for (int i = 0; i <n ; ++i) {
            isQue[row][i] = 1;
            if ( isTure(row,i,isQue)){
                string s(n,'.');
                s[i] = 'Q';
                path.push_back(s);
                backtracking(n,row + 1,isQue);
                path.pop_back();
            }
            isQue[row][i] = 0;
        }
        return;
    }

    bool isTure(int row,int clo,vector<vector<int>> &isQue){
        // 1. 保证竖排没有
        for (int i = 0; i < row; ++i) {
            if (isQue[i][clo] == 1)
                return false;
        }
        // 2. 保证45度没有
        int sum = 0;
        int x,y;
        for (x = row -1,y = clo -1; x >= 0 && y >= 0 ; --x,--y) {
            if (isQue[x][y] == 1)
                return false;
        }

        // 保证反斜45度没有
        for (x = row -1,y = clo +1; x >= 0 && y < isQue.size() ; --x,++y) {
            if (isQue[x][y] == 1)
                return false;
        }


        return true;
    }

};
#endif //P8_H51_N皇后_H
