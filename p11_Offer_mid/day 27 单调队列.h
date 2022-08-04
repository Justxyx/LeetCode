//
// Created by xm on 2022/8/4.
//

#ifndef P11_OFFER_MID_DAY_27_单调队列_H
#define P11_OFFER_MID_DAY_27_单调队列_H
/*
 * 单调队列问题
 *     核心： 维持一个单调队列 顺序递减
 */
class Solution {
public:
    struct AloneQue {
        deque<int> que;
        void add(int x) {
            while (!que.empty() && x > que.back()) {
                que.pop_back();
            }
            que.push_back(x);
        }
        void pop() {
            que.pop_front();
        }
        int maxQue() {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        AloneQue alone;
        for (int i = 0; i < k; ++i) {
            alone.add(nums[i]);
        }
        vector<int> res;
        res.push_back(alone.maxQue());
        for (int i = k; i < nums.size(); ++i) {
            int out = nums[i-k];  // 移出值
            int in = nums[i];   // 进入值
            if (out == alone.maxQue()) {
                alone.pop();
            }
            alone.add(in);
            res.push_back(alone.maxQue());
        }
        return res;
    }
};

class MaxQueue {
public:
    MaxQueue() {
    }

    int max_value() {
        if (que.empty())
            return -1;
        return aloneQue.front();
    }

    void push_back(int value) {
        que.push_back(value);

        while (!aloneQue.empty() && aloneQue.back() < value) {
            aloneQue.pop_back();
        }
        aloneQue.push_back(value);
    }

    int pop_front() {
        if (que.empty())
            return -1;
        int temp = que.front();
        if (temp == aloneQue.front())
            aloneQue.pop_front();
        que.pop_front();
        return temp;
    }

private:
    deque<int> que;
    deque<int> aloneQue;
};

#endif //P11_OFFER_MID_DAY_27_单调队列_H
