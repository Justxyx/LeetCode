//
// Created by xm on 2022/8/3.
//

#ifndef P11_OFFER_MID_DAY_24_H
#define P11_OFFER_MID_DAY_24_H
/*
 *    1    ->  1
 *    2    ->  1
 *    3    ->  2
 *    4    ->  3
 *    5    ->  1 + 4  2 + 3  = 6
 *    6    ->  9
 *    7    ->  12
 *    8    ->  18
 *    9    ->  24
 *    10   ->  36
 */
class Solution1 {
public:
    int cuttingRope(int n) {
        if (n < 7) {
            switch (n) {
                case 1:
                    return 1;
                case 2:
                    return 1;
                case 3:
                    return 2;
                case 4:
                    return 4;
                case 5:
                    return 6;
                case 6:
                    return 9;
            }
        }
        vector<int> res(n+1, 0);
        res[5] = 6;
        res[6] = 9;
        for (int i = 7; i <= n; ++i) {
            res[i] = max(res[i-2] * 2, res[i-3] * 3);
        }
        return res.back();
    }
};


/*
 *   n/2 ( a + b) = target;
 *   n/2 ( a + n -1 ) = target;
 */
class Solution2 {
public:
    static bool comp(vector<int> &v1, vector<int> &v2) {
        return v2[0] > v1[0];
    }
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int> path;
        vector<vector<int>> res;
        for (int i = 2; i < target; ++i) {
            if ( (i & 1) == 1 ) { // 奇数
                if (target%i == 0 && (target/i) - i/2 > 0) {
                    int count = -i/2;
                    while (count <= i/2) {
                        path.push_back(target/i + count);
                        ++ count;
                    }
                    res.push_back(path);
                    path.clear();
                }
            } else {  // 偶数
                int value = target/ i;
                if (target%(2*value+1) != 0 || (value - i/2) < 0 )
                    continue;
                else {
                    int count = i/2 -1;
                    int temp = value - count;
                    for (int j = 0; j < i; ++j) {
                        path.push_back(temp+j);
                    }
                    res.push_back(path);
                    path.clear();
                }
            }
        }
        std::sort(res.begin(), res.end(), comp);
        return res;
    }

};

/*
 *   f(n, m)
 *   f(1,3) = 1
 *   f(2,3) = 1
 */
class Solution {
public:
    int lastRemaining(int n, int m) {

        int f = 0;
        for (int i = 2; i <= n; ++i) {
            f = (f+m)%i;
        }

        return ++f;
    }
};

#endif //P11_OFFER_MID_DAY_24_H
