//
// Created by 肖应雄 on 2022/2/28.
//

#ifndef P6_P20_H
#define P6_P20_H

class Solution {
public:
    bool isValid(string s) {
        string left = "[{(";
        string right = "}])";
        stack<char> stack;

        for (char &item : s){
//            cout << item + 0<< endl;
            if (left.find(item) != -1){
                stack.push(item);
            }
            else{
                if (stack.size() == 0)
                    return false;
                char c = stack.top();
                stack.pop();
                if ((c + 1) == item || (c + 2 ) == item){
                    continue;
                } else{
                    return false;
                }
            }
        }
        if (!stack.size())
            return true;
        else
            return false;
    }
};

#endif //P6_P20_H
