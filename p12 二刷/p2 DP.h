//
// Created by xm on 2022/9/1.
//

#ifndef P12__P2_DP_H
#define P12__P2_DP_H
/*
 * 第一周
 */
class Solution509 {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int f0 = 0, f1 = 1;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = f0 + f1;
            f0 = f1;
            f1 = res;
        }
        return res;
    }
};

class Solution70 {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }
};

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 3)
            return min(cost[0], cost[1]);
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp.back(), dp[dp.size()-2]);
    }
};

/*
 * 第二周
 */
class Solution62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = INT_MIN;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] != INT_MIN)
                obstacleGrid[i][0] = 1;
            else
                break;
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] != INT_MIN)
                obstacleGrid[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int a, b;
                if (obstacleGrid[i][j] == INT_MIN)
                    continue;
                obstacleGrid[i][j-1] == INT_MIN ? a = 0 : a = obstacleGrid[i][j-1];
                obstacleGrid[i-1][j] == INT_MIN ? b = 0 : b = obstacleGrid[i-1][j];
                obstacleGrid[i][j] = a + b;
            }
        }
        if (obstacleGrid.back().back() == INT_MIN)
            return 0;
        return obstacleGrid.back().back();
    }
};

class Solution343 {
public:
    int integerBreak(int n) {
        if (n < 3)
            return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            int maxs = 0;
            for (int j = 1; j < i; ++j) {
                maxs = max(max(maxs, j * (i-j)), (i-j) * dp[j]);
            }
            dp[i] = maxs;
        }
        return dp.back();
    }
};

class Solution123_ {
public:
    /*
     * f1 =1;
     * f2 = 2;
     * f3 = 5;
     */
    int numTrees(int n) {
        if (n < 3)
            return n;
        vector<int> dp(n+1, 1);
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            // left
            int sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += dp[j] * dp[i-j-1];
//                cout << j << ":" <<  i-j-1<< endl;
            }
            dp[i] = sum;
        }
        return dp.back();
    }
};


/*
 * 第三周
 */
class Solution416 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (const auto &item : nums) {
            for (int i = sum; i > 0; --i) {
                cout << i - item << endl;
                if (i-item >= 0 && dp[i-item] == 1) {
                    dp[i] = 1;
                }
            }
            if (dp.back() == 1)
                return true;
        }
        return false;
    }
};

class Solution1049 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum/2+1, 0);
        int maxs = 0;
        dp[0] = 1;
        for (const auto &item : stones) {
            for (int i = sum/2; i > 0 ; --i) {
                if (i-item >= 0 && dp[i-item] == 1) {
                    dp[i] = 1;
                    maxs = max(maxs, i);
                }
            }
        }
        return sum - 2 * maxs;
    }
};

/*
 * 第四周
 */
class Solution494 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
         *  正   a    负    b
         *  a - b = target;
         *  a+b = sum(nums);
         *  2a = target + sum;
         */
        if (nums.empty())
            return 0;

        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums < abs(target))
            return 0;
        if ((target + sums) % 2 == 1)
            return 0;
        int temp = (target + sums)/2;
        vector<int> dp(temp+1, 0);
        dp[0] = 1;
        for (const auto &item : nums) {
            for (int i = dp.size()-1; i >=0; --i) {
                if (i - item >= 0 && dp[i-item] != 0) {
                    dp[i] = dp[i-item] + dp[i];
//                    cout << i - item << endl;
                }
            }
        }
        return dp.back();
    }
};


class Solution474 {
public:
    //  m -> 0   n -> 1
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (const auto &item : strs) {
            int x = 0, y= 0;
            for (int i = 0; i < item.size(); ++i) {
                if (item[i] == '0')
                    ++x;
                else
                    ++y;
            }
            for (int i = m; i >= x; --i) {
                for (int j = n; j >= y; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-x][j-y]+1);
                }
            }
        }
        return dp.back().back();
    }

};

class Solution518 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (const auto &item : coins) {
            for (int i = item; i < dp.size(); ++i) {
                dp[i] += dp[i-item];
            }
        }
        return dp.back();
    }
};

/*
 * 第五周
 */
class Solution377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (const auto &item : nums) {
                if (i-item >=0 && dp[i-item] != 0) {
                    dp[i] += dp[i-item];
                }
            }
        }
        return dp.back();
    }
};


class Solution701 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < 3; ++j) {
                if (i-j >= 0 && dp[i-j] != 0)
                    dp[i] += dp[i-j];
            }
        }
        return dp.back();
    }
};

class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (const auto &item : coins) {
                if (i - item >= 0 && dp[i-item] != 0) {
                    if (i - item == 0)
                        dp[i] = 1;
                    else if (dp[i] == 0)
                        dp[i] = dp[i-item]+1;
                    else
                        dp[i] = min(dp[i-item]+1, dp[i]);
                }
            }
        }
        if (dp.back() == 0)
            return -1;
        return dp.back();
    }
};

class Solution279完全平方数 {
public:
    int numSquares(int n) {
        vector<int> bag;
        for (int i = 1; pow(i,2) < n; ++i) {
            bag.push_back(pow(i, 2));
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (const auto &item : bag) {
                if (i-item >= 0 && dp[i-item] != 0) {
                    if (i-item == 0)
                        dp[i] = 1;
                    else if (dp[i] == 0)
                        dp[i] = 1 + dp[i-item];
                    else
                        dp[i] = min(dp[i], dp[i-item]+1);
                }
            }
        }
        return dp.back();
    }
};

/*
 * 第六周
 */
class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (const auto &item : wordDict) {
                if (i  < item.size() || dp[i-item.size()] == 0)
                    continue;
                string str1 =  string(s.begin()+i-item.size(), s.begin()+i);
                cout << str1 << endl;
                if (string(s.begin()+i-item.size(), s.begin()+i) == item)
                    dp[i] = 1;
            }
        }
        return dp.back();
    }
};

class Solution198 {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        // 0 偷  1  不偷
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = dp[i-1][1] + nums[i];  // 今天投
            dp[i][1] = max(dp[i-1][1] , dp[i-1][0]);  // 不偷
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};


class Solution213 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[1][0] = max(nums[0], nums[1]);
        dp[1][1] = nums[1];
        dp[0][1] = 0;
        for (int i = 2; i < nums.size(); ++i) {
            dp[i][0] = max(dp[i-2][0] + nums[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][1] + nums[i], dp[i-1][1]);
        }
        return max(dp[dp.size()-2][0], dp.back()[1]);
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solutionx {
public:
    int rob(TreeNode* root) {
        vector<int> res = find(root);
        return max(res[0], res[1]);
    }

    vector<int> find(TreeNode *node) {
        if (node == nullptr)
            return {0, 0};
        //  0  偷  1  不偷
        vector<int> left = find(node->left);
        vector<int> right = find(node->right);

        return {node->val + left[1] + right[1], max(left[0], left[1]) + max(right[0], right[1]) };
    }
};


class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int has = prices[0];
        int no_has = 0;
        for (int i = 1; i < prices.size(); ++i) {
            no_has = max(no_has, prices[i] - has);
            has = min(has, prices[i]);
        }
        return no_has;
    }
};
/*
 * week5 -----------------------
 */
class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int has = -prices[0];
        int no_has = 0;
        for (int i = 1; i < prices.size(); ++i) {
            no_has = max(no_has, prices[i] + has);   // 不持有
            has = max(has, no_has - prices[i]);
        }
        return no_has;
    }
};

class Solution123 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));  //   1 2 第一次买入卖出 34 第二次买入卖出

        dp[0][1] = -prices[0]; // 第一次持有
        dp[0][2] = 0;   // 第一次不持有
        dp[0][3] = -prices[0];   // 第二次持有
        dp[0][4] = 0;   // 第二次不持有

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = max(dp[i-1][1], - prices[i]);  // 持有 昨天持有 今天也持有  昨天不持有 今天持有
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]); // 不持有  昨天不持有 今天也不持有 昨天持有 今天卖掉

            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);   // 第二次持有
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]) ; // 第二次不持有 在第二次持有的基础上卖掉
        }
        return max(dp.back()[2], dp.back()[4]);
    }
};

class Solution188 {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1, 0));
        // 奇数持有  双数不持有

        // 初始化
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j < 2*k+1; j = j+2) {
                dp[i][j] = -prices[0];
            }
        }

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = max(dp[i-1][1], -prices[i]);  // 第一次持有
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);  // 第一次不持有

            for (int j = 3; j < 2*k+1; ++j) {
                if (j & 1 == 1) {   // 奇数 持有
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                } else {  // 偶数 不持有
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                }
            }
        }

        int res = 0;
        for (int i = 2; i < 2*k+1; i = i+2) {
            res = max(res, dp.back()[i]);
        }
        return res;
    }
};

class Solution309 {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        /*
         *      1  ->  持有
         *      2  ->  不持有 当天卖出  第二天冷冻
         *      3  ->  不持有 但不是当天卖出
         */
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = max(dp[i-1][1],dp[i-1][3] -prices[i]);  // 持有
            dp[i][2] = dp[i-1][1] + prices[i];
            dp[i][3] = max(dp[i-1][2], dp[i-1][3]);
        }
        return max(dp.back()[2], dp.back()[3]);
    }
};


/*
 *   ------ week 7
 */

class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        // 1 持有  2 不持有
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i] - fee);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        }
        return dp.back()[2];
    }
};

class Solution300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int max_index = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j] > max_index)
                    max_index = dp[j];
            }
            dp[i] = max_index + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};


class Solution674 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                ++ count;
            else {
                res = std::max(count, res);
                count = 1;
            }
        }
        return res;
    }
};

class Solution718 {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxs = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                    maxs = max(dp[i+1][j+1], maxs);
                }
            }
        }
        return maxs;
    }
};

class Solution1143 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

class Solution1035 {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp.back().back();
    }
};
class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = INT_MIN;
        int sum = 0;
        for (const auto &item : nums) {
            sum += item;
            maxs = (sum, maxs);
            if (sum < 0)
                sum = 0;
        }
        return maxs;
    }
};

class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty() || t.empty())
            return false;
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for (int i = 1; i <= t.size(); ++i) {
            if (s[0] == t[i-1])
                dp[1][i] = 1;
            else
                dp[1][i] = dp[1][i-1];
        }
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};

class Solution115 {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty())
            return 0;
//        s.swap(t);
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        // 初始化
        for (int i = 1; i <= t.size(); ++i) {
            if (s[0] == t[i-1])
                dp[1][i] = dp[1][i-1] + 1;
            else
                dp[1][i] = dp[1][i-1];
        }
        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};


class Solution583 {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        // 初始化
        for (int i = 0; i < dp[0].size(); ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1] + 2);
            }
        }
        return dp.back().back();
    }
};

/*
 *   a   a    a
 * a
 * a
 * a
 */

class Solution {
public:
    int count = 0;
    vector<char> path;
    int countSubstrings(string s) {
        backtracking(s, 0);
        return count;
    }

    void backtracking(string &str, int index) {
        if (judeg()) {
            ++ count;
            string temp = string(path.begin(), path.end());
            cout << temp << endl;
        }
        if (index >= str.size())
            return;
        for (int i = index; i < str.size(); ++i) {
            path.push_back(str[i]);
            backtracking(str, i+1);
            path.clear();
        }
    }

    bool judeg() {
        if (path.empty())
            return false;
        if (path.size() == 1)
            return true;
        int left = 0;
        int right = path.size()-1;
        while (left < right) {
            if (path[left] != path[right])
                return false;
            ++ left;
            -- right;
        }
        return true;
    }
};
#endif //P12__P2_DP_H
