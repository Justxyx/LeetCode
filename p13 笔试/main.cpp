#include <iostream>


// 8.6 科大讯飞


class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 寻找包含e的单词的个数
     * @param string string字符串 输入字符串，不同单词用空格隔开
     * @return int整型
     */
    int findEwordCount(string string) {
        // write code here
        if (string.empty())
            return 0;
        int count = 0;
        bool b = false;
        for (int i = 0; i < string.size(); ++i) {
            if (string[i] == ' ') {
                b = false;
                continue;
            }

            if (b)
                continue;

            if (string[i] == 'e' || string[i] == 'E') {
                ++ count;
                b = true;
            }

        }
        cout << count << endl;
        return count;
    }
};

/*
 * 求凸四边形面积  没A出来
 */
struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};
class Solution2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求四个点的面积
     * @param p1 Point类 点1
     * @param p2 Point类 点2
     * @param p3 Point类 点3
     * @param p4 Point类 点4
     * @return long长整型
     */
    long long getArea(Point p1, Point p2, Point p3, Point p4) {
        vector<int> x{p1.x,p2.x,p3.x,p4.x};
        vector<int> y{p1.y,p2.y,p3.y,p4.y};
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        // write code here
        // 1. 构造5边形
        int border = p2.x - p4.x;
        int h_sum = p3.y - p1.y;
        int h1 = p4.y - p1.y;
        int h2 = p2.y - p1.y;
        // 五边形面积
        double sum_are_5 = (h_sum+h1) * (p1.x-p4.x)/2.0 + (h2 + h_sum) * (p2.x-p1.x)/2.0;
        // 减去两个三角形
        double res = sum_are_5 - (p1.x - p4.x)*h1/2.0 - (p2.x - p1.x)*h2/2.0;
        cout << res << endl;
        return res;
    }
};






class Solution3 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 查找"iflytek"子串
     * @param str string字符串 输入字符串
     * @return int整型
     */
    int findIflytek(string str) {
        if (str.empty())
            return 0;
        // write code here
        string ifly = "iflytek";
        vector<vector<int>> dp(ifly.size()+1, vector<int>(str.size()+1, 0));
        // 初始化
        for (int i = 0; i < str.size(); ++i) {
            if (ifly[0] == str[i])
                dp[1][i+1] = dp[1][i] + 1;
            else
                dp[1][i+1] = dp[1][i];
        }
        for (int i = 1; i < ifly.size(); ++i) {
            for (int j = 0; j < str.size(); ++j) {
                int x = i+1;
                int y = j+1;
                if (ifly[i] == str[j]) {
                    dp[x][y] = dp[x-1][y] + dp[x][y-1];
                } else
                    dp[x][y] = dp[x][y-1];
            }
        }
        cout << dp.back().back();
        return dp.back().back();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
