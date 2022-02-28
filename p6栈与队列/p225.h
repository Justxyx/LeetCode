//
// Created by 肖应雄 on 2022/2/28.
//

#ifndef P6_P225_H
#define P6_P225_H
class MyStack {
private:
    queue<int> que;
    int item;
    int len;
public:
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        reverse();
        item = que.front();
        que.pop();
        return item;
    }

    int top() {
        reverse();
        item = que.front();
        que.pop();
        que.push(item);
        return item;
    }

    bool empty() {
        if (que.size())
            return false;
        else
            return true;
    }

    void reverse(){
        len = que.size();
        while (len > 1){
            item = que.front();
            que.pop();
            que.push(item);
            --len;
        }
    }
};

#endif //P6_P225_H
