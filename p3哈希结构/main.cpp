#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>


/**
 *      解题思路如下：
 *          是这样的，如果求平方过后的sum  重复出现  则return false
 *          否则 一直循环计算  直到sum = 1；
 */




class Solution {
public:

    // 1. 求各位的平方
    int getItem(int n){
        int sum = 0;
        while (n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum ;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1){
             n = getItem(n);
            if ( n == 1){
                return true;
            }
            if (set.find(n) == set.end()){
                set.insert(n);
            } else{
                return false;
            }
        }
    }
};



int main() {

    Solution solution;
    cout << solution.isHappy(2) << endl;



    return 0;
}
