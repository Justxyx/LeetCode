#include <iostream>
#include <stack>
using namespace std;

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
        int temp = s1.top();
        s1.pop();
        return temp;
    }

private:
    stack<int> s1;
    stack<int> s2;
};
int main() {
    CQueue c;
    c.appendTail(1);
    c.appendTail(2);
    c.appendTail(3);
    c.appendTail(4);

    cout << c.deleteHead() << endl;
    return 0;
}
