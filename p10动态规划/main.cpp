#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_value = INT_MIN;  // 只买入一次 获利
        int second_value = INT_MIN;  // 买入两次 获利

        int has = -prices[0];
        int no_has = 0;

        // 买卖两次出参数
        int second_has = INT_MIN;
        int second_no_has = 0;

        int sum = 0;

        for (int i = 1; i < prices.size(); ++i) {

            // 计算一次买入卖出
            int temp_has = has;
            int temp_no_has = no_has;
            has = max(has,-prices[i]);
            no_has = max(no_has, prices[i] + temp_has);

            // 计算二次买入卖出
            if (second_has != INT_MIN) {

                int second_temp_has = second_has;
                int second_temp_no_has = second_no_has;
                second_has = max(second_has, -prices[i]);
                second_no_has = max(second_no_has, prices[i] + second_temp_has);
            }

            if (no_has > temp_no_has || i == prices.size()-1) {
                first_value = temp_no_has;
                second_value = second_no_has;

                if (second_value == INT_MIN)
                    sum = first_value;
                else{
                    int s = max(first_value + second_no_has,no_has);
                    sum = max(sum,s);

                }

                second_has = -prices[i];
                second_no_has = 0;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> v{6,1,3,2,4,7};
    Solution solution;
    cout << solution.maxProfit(v);
    return 0;
}

