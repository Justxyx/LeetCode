//
// Created by 肖应雄 on 2022/2/27.
//
/**
 *  其实这个实现不算太好
 *  可以用两个栈实现 3个栈太麻烦了
 */
#ifndef P6_P232_H
#define P6_P232_H

class MyQueue {
public:

    stack<int> stackA;
    stack<int> stackB;
    stack<int> stackC;
    int item = 0;

    MyQueue() {

    }

    void push(int x) {
        stackA.push(x);
    }

    int pop() {
        if (stackB.size() == 0){
            reverseB();
        }
        item = stackB.top();
        stackB.pop();
        return item;
    }

    int peek() {
        if (stackB.size() == 0){
            reverseB();
        }
        item = stackB.top();
        return item;
    }

    bool empty() {
        reverseB();

        return !stackB.size();
    }

    void reverseB(){
        // A is not null
        if (stackA.size() != 0){
            while ( stackB.size() != 0){
                item = stackB.top();
                stackB.pop();
                stackC.push(item);
            }
            while (stackA.size() !=0){
                item = stackA.top();
                stackA.pop();
                stackB.push(item);
            }
        }
        while (stackC.size() != 0){
            item = stackC.top();
            stackC.pop();
            stackB.push(item);
        }
    }
};
#endif //P6_P232_H
