//
// Created by xm on 2022/7/7.
//

#ifndef P11_OFFER_MID_H30_MIN_STACK_H
#define P11_OFFER_MID_H30_MIN_STACK_H

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        int min_ele = x;
        if (!v.empty())
            min_ele = std::min(v.back().second, x);
        v.push_back(make_pair(x, min_ele));
    }

    void pop() {
        if (!v.empty())
            v.pop_back();
    }

    int top() {
        if (!v.empty())
            return v.back().first;
        return -1;
    }

    int min() {
        if (!v.empty())
            return v.back().second;
        return -1;
    }

private:
    vector<pair<int,int>> v;
};
#endif //P11_OFFER_MID_H30_MIN_STACK_H
