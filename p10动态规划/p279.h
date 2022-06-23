//
// Created by xm on 2022/6/23.
//

#ifndef P10_P279_H
#define P10_P279_H

class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n+1,0);
        int bag = sqrt(n);
//        if (bag * bag == n)
//            return 1;
//        else
//            ++ bag;
        for (int i = bag; i >0 ; --i) {
            for (int j = 1; j < res.size(); ++j) {
                // 0
                if (pow(i,2) - j == 0) {
                    res[pow(i,2)] = 1;
                } else if ( j - pow(i,2) > 0 && res[j - pow(i,2)] != 0){
                    if (res[j] == 0)
                        res[j] = res[j- pow(i,2)] + 1;
                    else
                        res[j] = min(res[j- pow(i,2)]+1,res[j]);

                }
            }
        }
        return res.back();
    }
};
#endif //P10_P279_H
