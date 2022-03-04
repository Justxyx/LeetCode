//
// Created by 肖应雄 on 2022/3/4.
//

#ifndef P6_H239_H
#define P6_H239_H
/**
 * 超时解法
 */


/**
 * 挂了 超出时间限制
 */
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int>::iterator begin = nums.begin();
//        vector<int>::iterator end = nums.end();
//        vector<int>::iterator temp;
//        vector<int> res;
//        int max = NULL;
//
//        while ((begin+k) <= end){
//            temp = begin;
//            for (int i = 0; i < k; ++i) {
//                if (max == NULL){
//                    max = *temp;
//                } else if (max < *temp){
//                    max = * temp;
//                }
//                ++temp;
//            }
//            res.push_back(max);
//            max = NULL;
//            ++ begin;
//        }
//        return res;
//    }
//};

//单调队列
class aloneQue{
private:
    deque<int> deque;
public:
    int pop(){
        int temp = deque.front();
        deque.pop_front();
        return temp;
    }
    void push(int x){
        while (deque.size() > 0 && deque.back() < x){
            deque.pop_back();
        }
        deque.push_back(x);
    }
    int top(){
        return deque.front();
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        aloneQue aloneQue;
        int i;
        for ( i = 0; i < k-1; ++i) {
            aloneQue.push(nums[i]);
        }
//        --i;
        vector<int> res;
        int temp;
        while (i < nums.size()){
            aloneQue.push(nums[i]);
            res.push_back(aloneQue.top());
            if (aloneQue.top() == nums[i+1-k])
                aloneQue.pop();
            ++i;
        }
        return res;
    }
};
#endif //P6_H239_H
