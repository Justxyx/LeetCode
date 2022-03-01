//
// Created by 肖应雄 on 2022/3/1.
//

#ifndef P6_P150_H
#define P6_P150_H
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string symbol = "+-*/";
        stack<int> stack;
        int x,y;
        for (const string &item : tokens){
//            cout << item << endl;
            int i = symbol.find(item);
            if (i < 0){  // 数字
                stack.push(atoi(item.c_str()));
            } else{
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                if (item == "+")
                    stack.push(x+y);
                else if ( item == "-")
                    stack.push(y-x);
                else if (item == "*")
                    stack.push(x*y);
                else
                    stack.push(y/x);
            }
        }
        return stack.top();
    }
};
#endif //P6_P150_H
