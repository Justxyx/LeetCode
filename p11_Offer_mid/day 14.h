//
// Created by xm on 2022/7/22.
//

#ifndef P11_OFFER_MID_DAY_14_H
#define P11_OFFER_MID_DAY_14_H

class Solution1 {
public:
    vector<char> path;
    vector<vector<int>> bind;
    string words;
    bool b = false;
    bool exist(vector<vector<char>>& board, string word) {
        words = word;
        bind = vector<vector<int>>(board.size(),vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {

                bind[i][j] = 1;
                path.push_back(board[i][j]);
                backtracking(board, i, j);
                path.pop_back();
                bind[i][j] = 0;
            }
        }
        return b;
    }

    void backtracking(vector<vector<char>> &borad, int x, int y) {
        string str = "";
        for (const auto &item : path)
            str += item;
        if (str != words.substr(0, str.size()))
            return;
        if ((int)path.size() == (int)words.size()) {
            if (str == words)
                b = true;
            return;
        }
        if (path.size() > words.size())
            return;


        if ((y+1 < borad[0].size()) && bind[x][y+1] == 0 && (x < borad.size() && y < borad[0].size())) {
            bind[x][y+1] = 1;
            path.push_back(borad[x][y+1]);
            backtracking(borad,x, y+1);
            path.pop_back();
            bind[x][y+1] = 0;
        }

        if ((y-1 >= 0) && bind[x][y-1] == 0 && (x < borad.size() && y < borad[0].size())) {

            bind[x][y-1] = 1;
            path.push_back(borad[x][y-1]);
            backtracking(borad,x, y-1);
            path.pop_back();
            bind[x][y-1] = 0;
        }

        if ((x+1 < borad.size()) && (x < borad.size() && y < borad[0].size()) && bind[x+1][y] == 0) {
            bind[x+1][y] = 1;
            path.push_back(borad[x+1][y]);
            backtracking(borad,x+1, y);
            path.pop_back();
            bind[x+1][y] = 0;
        }


        if ( (x-1 >= 0) && (x < borad.size() && y < borad[0].size()) && bind[x-1][y] == 0) {
            bind[x-1][y] = 1;
            path.push_back(borad[x-1][y]);
            backtracking(borad,x-1, y);
            path.pop_back();
            bind[x-1][y] = 0;
        }
    }
};

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> v(m, vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (resolve(i) + resolve(j) > k)
                    v[i][j] = -1;
            }
        }

//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout << v[i][j] << ",";
//            }
//            cout << endl;
//        }

        v[0][0] = 1;
        int count = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == 1 || v[i][j] == -1)
                    continue;

                if (i-1 >= 0 && v[i-1][j] == 1)
                    v[i][j] = 1;
                else if (j-1 >= 0 && v[i][j-1] == 1)
                    v[i][j] = 1;
                else if ((i+1 < m) && (v[i+1][j] == 1))
                    v[i][j] = 1;
                else if ((j+1< n) && (v[i][j+1] == 1))
                    v[i][j] = 1;
                else
                    continue;
                ++ count;
            }
        }
        return count;
    }

    int resolve(int i) {
        int count = 0;
        while (i > 0) {
            count += (i%10);
            i /= 10;
        }
        return count;
    }
};

#endif //P11_OFFER_MID_DAY_14_H
