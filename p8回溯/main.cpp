#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>
#include <set>

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



//"Q...",
//"...Q",
//".Q..",
//"..Q."],

int main() {

Solution solution;
//    int i[2];
//    cout << i[5] << endl;
//vector<vector<string>> res = solution.solveNQueens(5);
//    for (const auto &item : res)
//        for (const auto i : item)
//            cout << i << "," ;




vector<vector<int>> test(4,vector<int>(4,0));
test[0][0] = 1;
test[1][3] = 1;
    test[2][1] = 1;
    test[3][2] = 1;
cout << solution.isTure(3,2,test);


//
//    Solution solution;
//   vector<string> res = solution.findItinerary(tickets);
//    for (const auto &item : res)
//        cout << item << endl;

}
