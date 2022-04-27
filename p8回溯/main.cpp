#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>
#include <set>


class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> bank(n,0);
        backtracking(n,bank);

//        for (const auto &item : res){
//            for (const auto &i : item){
//                cout << i << ",";
//            }
//            cout << endl;
//        }

        return trans();
    }

    vector<vector<string>> trans(){
        vector<string> line;
        vector<vector<string>> tostrs;
        string str = "";
        for (const auto &item : res){
            for (const auto &i : item){
                str = tostr1(i,item.size());
                line.push_back(str);
            }
            tostrs.push_back(line);
            line.clear();
        }
        return tostrs;
    }

    string tostr1(int index,int n){
        string str = "";
        for (int i = 0; i < n; ++i) {
            if (i == index)
                str += "Q";
            else
                str += ".";
        }
        return str;
    }


    void backtracking(int n,vector<int> &bank){
        if (path.size() == n)
            res.push_back(path);
        if (path.size() > n)
            return;

        for (int i = 0; i < n; ++i) {

            if (path.empty()){
                path.push_back(i);
                bank[i] = 1;
            } else{
                if (bank[i] == 1)
                    continue;
                int end = path.back();
                if ( (i == (end+1)) || (i == (end - 1)) )
                    continue;
                path.push_back(i);
                bank[i] = 1;
            }

            backtracking(n,bank);
            path.pop_back();
            bank[i] = 0;
        }
        return;
    }


};





int main() {

Solution solution;
vector<vector<string>> res =  solution.solveNQueens(4);
    for (const auto &item : res[0])
        cout << item << endl;

//
//    Solution solution;
//   vector<string> res = solution.findItinerary(tickets);
//    for (const auto &item : res)
//        cout << item << endl;

}
