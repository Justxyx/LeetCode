#include <iostream>
#include <stack>
using namespace std;


int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    int i = queue.pop();
    cout << i << endl;
    return 0;
}
