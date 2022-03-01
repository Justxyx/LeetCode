//
// Created by 肖应雄 on 2022/3/1.
//

#ifndef P6_P1047_H
#define P6_P1047_H
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (stack.size() == 0)
                stack.push(s[i]);
            else{
                if (stack.top() == s[i]){
                    stack.pop();
                } else{
                    stack.push(s[i]);
                }
            }
        }
        string result = "";
        while (!stack.empty()) { // 将栈中元素放到result字符串汇总
            result += stack.top();
            stack.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;
    }
};
#endif //P6_P1047_H
