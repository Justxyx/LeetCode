#include <iostream>
#include <stack>
using namespace std;
#include <queue>
#include <list>
#include <vector>





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

int main() {
    Solution solution;
    vector<int> v{1,-1};
    solution.maxSlidingWindow(v,1);
}
