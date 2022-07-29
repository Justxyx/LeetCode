//
// Created by xm on 2022/7/29.
//

#ifndef P11_OFFER_MID_DAY_17_H
#define P11_OFFER_MID_DAY_17_H

class Solution1 {
public:

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        multiset<int> sets;
        for (const auto &item : arr) {
            sets.insert(item);
        }
        vector<int> v;
        int i = 0;
        auto p = sets.begin();
        while (i < k) {
            v.push_back(*p);
            ++p;
            ++i;
        }
        return v;
    }
};
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

    }

    double findMedian() {

    }

private:
    int media;
};

#endif //P11_OFFER_MID_DAY_17_H
