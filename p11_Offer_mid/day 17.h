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
        mins.push_back(0);
        maxs.push_back(0);
    }

    void addNum(int num) {
        // 核心思想 保证大顶堆最大数比小顶堆最小数小
        maxs.push_back(num);
        MaxHeap();
        if (maxs.size() > mins.size()) {
            mins.push_back(maxs[1]);
            swap(maxs[1], maxs.back());
            maxs.resize(maxs.size()-1);
            MaxHeap();
            minHeap();
        }
        if (maxs.size() == mins.size()) {
            mins.push_back(maxs[1]);
            swap(maxs[1], maxs.back());
            maxs.resize(maxs.size()-1);
            MaxHeap();
            minHeap();
            maxs.push_back(mins[1]);
            swap(mins[1], mins.back());
            mins.resize(mins.size()-1);
            MaxHeap();
            minHeap();
        }
    }

    double findMedian() {
        vector<int> s = maxs;
        if (mins.size() > maxs.size())
            return mins[1];
        double i = (maxs[1] + mins[1])/2.0;
        return i;
    }


    void test() {
        vector<int> &s = maxs;
        s = {1,2,3};
        MaxHeap();
        s[1];
    }

    void MaxHeap() {
        for (int i = (maxs.size()-1)/2; i > 0; --i) {
            adjust(true, i);
        }
    }
    void minHeap() {
        for (int i = (mins.size()-1)/2; i > 0; --i) {
            adjust(false, i);
        }
    }
    void adjust(bool b, int index) {
        int temp = 2 * index;
        if (b) {
            if (temp+1 < maxs.size() && maxs[temp+1] > maxs[temp])
                ++temp;
            if (maxs[index] > maxs[temp])
                return;
            swap(maxs[index], maxs[temp]);
            return;
        }
        if (!b) {
            if (temp+1 < mins.size() && mins[temp+1] < mins[temp])
                ++temp;
            if (mins[index] < mins[temp])
                return;
            swap(mins[index], mins[temp]);
            return;
        }

    }
private:
    vector<int> mins;
    vector<int> maxs;
};


#endif //P11_OFFER_MID_DAY_17_H
