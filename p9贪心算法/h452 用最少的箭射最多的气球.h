//
// Created by 肖应雄 on 2022/5/18.
//
/*
 *  这道题目最起码提交了35次
 *  最大的感受！
 *
 *  函数能传递引用就传递引用哇！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 *  要不会超时哇！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 */
#ifndef P9_H452_用最少的箭射最多的气球_H
#define P9_H452_用最少的箭射最多的气球_H
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(),com);
        int count = 1;
        int left = points[0][0];
        int right = points[0][1];
        for (const auto &item : points){


            if (item[0] > right){
                ++ count;
                left = item[0];
                right = item[1];
            }

            if (item[0] > left)
                left = item[0];
            if (item[1] < right)
                right = item[1];

        }
        return count;
    }

    static bool com(vector<int> &r1,vector<int> &r2){
        return (r2[0] > r1[0]);
    }
};
#endif //P9_H452_用最少的箭射最多的气球_H
