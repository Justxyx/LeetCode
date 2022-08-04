//
// Created by xm on 2022/8/4.
//

#ifndef P11_OFFER_MID_DAY_25_H
#define P11_OFFER_MID_DAY_25_H

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int x = matrix.size();
        int y = matrix[0].size();

        int i = 0, j = 0;
        bool b = true;
        while (1) {
            b = true;
            // 1.
            while ( j < y && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                ++j;
                b = false;
            }
            --j;
            ++i;
            while (i < x && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                ++ i;
                b = false;
            }
            -- i;
            -- j;
            while (j >= 0 && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                --j;
                b = false;
            }
            ++j;
            -- i;
            while (i >= 0 && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                --i;
                b = false;
            }
            ++ i;
            ++ j;
            if (b)
                break;
        }
        return res;
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;

        for (int k = 0; k < pushed.size(); ++k) {
            s.push(pushed[k]);
            while ( !s.empty() && s.top() == popped[i]) {
                ++ i;
                s.pop();
            }
        }

        if (s.empty())
            return true;
        else
            return false;

    }
};

#endif //P11_OFFER_MID_DAY_25_H
