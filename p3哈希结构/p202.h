//
// Created by 肖应雄 on 2022/1/19.
//

#ifndef P3_P202_H
#define P3_P202_H
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


#endif //P3_P202_H
