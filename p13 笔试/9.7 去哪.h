//
// Created by xm on 2022/9/7.
//

#ifndef P13__9_7_去哪_H
#define P13__9_7_去哪_H


//10,[[1,1],[2,3],[3,5],[5,10],[7,9],[8,10]]
class Solution_1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 运动员可得到的最高分
     * @param energy int整型 运动员体力值
     * @param actions int整型vector<vector<>> 二维数组i为动作号 actions[i][0]为动作i+1消耗体力,actions[i][1]为动作i+1得分
     * @return int整型
     */
    int maxScore(int energy, vector<vector<int> >& actions) {
        // write code here
        vector<int> dp(energy + 1, -1);
        dp[0] = 0;
        for (const auto &item : actions) {
            for (int i = dp.size(); i > 0; --i) {
                if (i - item[0] >= 0 && dp[i-item[0]] != -1)
                    dp[i] = max(dp[i], dp[i-item[0]] + item[1]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution_2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 解密
     * @param encryptedNumber int整型 待解密数字
     * @param decryption int整型 私钥参数D
     * @param number int整型 私钥参数N
     * @return int整型
     */
    int Decrypt(int encryptedNumber, int decryption, int number) {
        // write code here
        int temp = encryptedNumber;
        for (int i = 1; i < decryption; ++i) {
            temp = temp * encryptedNumber;
            while (temp > number)
                temp -= number;
        }
        return temp;
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 翻牌
     * @param inHand string字符串 一组以单空格间隔的手牌(例如：SA HK H9 D8 C5 S5 H4)
     * @return string字符串
     */
    void add_v(int h, char x, vector<vector<int>> &bind) {
        if (x == '1')
            bind[h][9] = 1;
        if (x == '2')
            bind[h][1] = 1;
        if (x == '3')
            bind[h][2] = 1;
        if (x == '4')
            bind[h][3] = 1;
        if (x == '5')
            bind[h][4] = 1;
        if (x == '6')
            bind[h][5] = 1;
        if (x == '7')
            bind[h][6] = 1;
        if (x == '8')
            bind[h][7] = 1;
        if (x == '9')
            bind[h][8] = 1;
        if (x == 'A')
            bind[h][0] = 1;
        if (x == 'J')
            bind[h][10] = 1;
        if (x == 'Q')
            bind[h][11] = 1;
        if (x == 'K')
            bind[h][12] = 1;
        return;
    }
    void resolve(const string &inHand, vector<vector<int>> &bind) {
        int i = 0;
        while (i < inHand.size()) {
            if (inHand[i] == 'S') {
                add_v(0, inHand[i+1], bind);
            } else if (inHand[i] == 'H')
                add_v(1, inHand[i+1], bind);
            else if (inHand[i] == 'C')
                add_v(2, inHand[i+1], bind);
            else if (inHand[i] == 'D')
                add_v(3, inHand[i+1], bind);

            ++ i;
        }
    }

    string judge(vector<vector<int>> &bind) {
        // 判断是否同花
        int isSame = -1;
        for (int i = 0; i < 4; ++i) {
            if (accumulate(bind[i].begin(), bind[i].end(), 0) >= -3) {
                isSame = i;
            }
        }

        // 1.
        if ((isSame != -1) && bind[isSame][0] == 1) {
            bool b = true;
            for (int i = 9; i < 13; ++i) {
                if (bind[isSame][i] == -1)
                    b = false;
            }
            if (b)
                return "HuangJiaTongHuaShun";
        }

        // 2.
        if (isSame != -1) {
            int count = 0;
            for (int i = 0; i < 13; ++i) {
                if (bind[isSame][i] != -1)
                    ++ count;
                else
                    -- count;

                if (count < 0)
                    count = 0;
                if (count >= 5)
                    return "TongHuaShun";
            }
        }

        // 3.
        for (int i = 0; i < 13; ++i) {
            int j;
            for (j = 0; j < 4; ++j) {
                if (bind[j][i] == -1)
                    break;
            }
            if (j == 4)
                return "SiTiao";
        }

        // 4.
        int sum_3 = 0;
        for (int i = 0; i < 13; ++i) {
            int count = 0;
            for (int j = 0; j < 4; ++j) {
                if (bind[j][i] == -1)
                    break;
                ++ count;
            }
            if (count > 1)
                sum_3 += count;
        }
        if (sum_3 == 5)
            return "HuLu";

        // 5.
        if (isSame != -1)
            return "TongHua";

        // 6.
        int count = 0;
        for (int j = 0; j < 13; ++j) {
            for (int i = 0; i < 4; ++i) {
                if (bind[i][j] != -1)
                {
                    ++ count;
                    break;
                }
            }
        }
        if (count >= 5)
            return "ShunZi";

        // 7.
        for (int i = 0; i < 13; ++i) {
            int count = 0;
            for (int j = 0; j < 4; ++j) {
                if (bind[j][i] == -1)
                    break;
                ++ count;
            }
            if (count > 2)
                return "SanTiao";
        }

        sum_3 = 0;
        for (int i = 0; i < 13; ++i) {
            int count = 0;
            for (int j = 0; j < 4; ++j) {
                if (bind[j][i] == -1)
                    break;
                ++ count;
            }
            if (count > 1)
                sum_3 += count;
        }
        if (sum_3 == 4)
            return "LiangDui";


        sum_3 = 0;
        for (int i = 0; i < 13; ++i) {
            int count = 0;
            for (int j = 0; j < 4; ++j) {
                if (bind[j][i] == -1)
                    break;
                ++ count;
            }
            if (count > 1)
                return "YiDui";
        }


        return "GaoPai";
    }
    string showDown(string inHand) {
        vector<vector<int>> bind(4, vector<int>(13, -1));   // S H C D  1 2 3 4
        resolve(inHand, bind);
        return judge(bind);
    }
};
#endif //P13__9_7_去哪_H
