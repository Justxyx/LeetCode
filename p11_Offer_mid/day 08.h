//
// Created by xm on 2022/7/18.
//

#ifndef P11_OFFER_MID_DAY_08_H
#define P11_OFFER_MID_DAY_08_H


class Solution1 {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        vector<int> fn(n+1,0);
        fn[0] = 0;
        fn[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fn[i] = (fn[i-1] + fn[i-2]) % 1000000007;
        }
        return fn.back();
    }
};

class Solution2 {
public:
    int numWays(int n) {
        if (n < 2)
            return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <=n ; ++i) {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[n];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int has = -prices[0];
        int no_has = 0;
        for (int i = 1; i < prices.size(); ++i) {
            has = max(has, -prices[i]);
            no_has = max(no_has, prices[i] + has);
        }
        return no_has;
    }
};
#endif //P11_OFFER_MID_DAY_08_H
