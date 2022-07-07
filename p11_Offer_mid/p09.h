//
// Created by xm on 2022/7/7.
//

#ifndef P11_OFFER_MID_P09_H
#define P11_OFFER_MID_P09_H
class CQueue {
public:
    CQueue() {
        stack<int> s1;
        stack<int> s2;
    }


    void appendTail(int value) {
        while ( !s1.empty()) {
            auto p = s1.top();
            s2.push(p);
            s1.pop();
        }
        s1.push(value);
        while (!s2.empty()) {
            auto p = s2.top();
            s1.push(p);
            s2.pop();
        }
    }

    int deleteHead() {
        if (s1.empty())
            return -1;
        int temp = s1.top();
        s1.pop();
        return temp;
    }

private:
    stack<int> s1;
    stack<int> s2;
};
#endif //P11_OFFER_MID_P09_H
