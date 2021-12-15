//
// Created by 肖应雄 on 2021/12/14.
//

#ifndef P1_P59_H
#define P1_P59_H
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

#endif //P1_P59_H
