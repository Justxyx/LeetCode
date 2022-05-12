//
// Created by 肖应雄 on 2022/5/12.
//

#ifndef P9_P860_H
#define P9_P860_H

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> doller(3,0);
        for (int i = 0; i < bills.size(); ++i) {
            switch (bills[i]) {
                case 5:
                    ++doller[0];
                    break;
                case 10:
                    --doller[0];
                    ++doller[1];
                    if (doller[0] < 0)
                        return false;
                    break;
                case 20:
                    if (doller[1] > 0){
                        --doller[1];
                        --doller[0];
                    } else{
                        doller[0] -= 3;
                    }
                    if (doller[0] < 0 || doller[1] < 0)
                        return false;
                    break;
            }
        }
        return true;
    }
};
#endif //P9_P860_H
