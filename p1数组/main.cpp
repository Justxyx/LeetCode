#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
//#include "p724.h"


// 59
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int i=0,j=0;    //  i 为横坐标 ， j 为纵坐标
        int count = 1;
        bool  b = true;
        int time = (n+1)/2;
        int big = n*n;
        int isJ = n%2;
        while (time>0){
//            1.
            for (int k = 0; k < n-1 ; ++k) {
                res[i][j++] = count++;
            }
//            2.
            for (int k2 = 0; k2 < n-1 ; ++k2) {
                res[i++][j] = count++;
            }

            for (int k2 = 0; k2 < n-1 ; ++k2) {
                res[i][j--] = count++;
            }

            for (int k2 = 0; k2 < n-1 ; ++k2) {
                res[i--][j] = count++;
            }
            if (time == 1 && (isJ) ){
                res[i][j] = big;
            }
            time --;
            n = n-2;
            i++;
            j++;

        }
        return res;
    }
};


int main() {

    int target = 1;
    Solution solution;
    auto a = solution.generateMatrix(target);
    for (const auto &item : a){
        for (const auto &item : item)
            cout << item << "," ;
        cout << endl;
    }
}
