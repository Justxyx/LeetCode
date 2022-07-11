//
// Created by xm on 2022/7/11.
//

#ifndef P11_OFFER_MID_DAY_05_H
#define P11_OFFER_MID_DAY_05_H
class Solution {
public:
    bool findTwo(vector<int> &bind, int target) {
        int left = 0;
        int right = bind.size() - 1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (bind[mid] == target)
                return true;
            else if (bind[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); ++i) {
            if(matrix[i].empty())
                return false;
            if (matrix[i][0] == target)
                return true;
            else if (matrix[i][0] < target){
                if (findTwo(matrix[i], target))
                    return true;
            } else
                continue;
        }
        return false;
    }
};

class Solution {
public:
    int minArray(vector<int>& numbers) {
        return *min_element(numbers.begin(), numbers.end());

    }
};

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> bind(26,0);
        for (const auto &item : s) {
            ++ bind[item - 97];
        }
        for (const auto &item : s) {
            if (bind[item-97] == 1)
                return item;
        }
        return ' ';
    }
};
#endif //P11_OFFER_MID_DAY_05_H
