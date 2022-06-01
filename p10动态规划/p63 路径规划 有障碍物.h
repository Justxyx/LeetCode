//
// Created by 肖应雄 on 2022/6/1.
//

#ifndef P10_P63_路径规划_有障碍物_H
#define P10_P63_路径规划_有障碍物_H
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // 纵
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        if(obstacleGrid.back().back() == -1 || obstacleGrid.front().front() == -1)
            return 0;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0)
                obstacleGrid[i][0] = 1;
            else
                break;
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 0)
                obstacleGrid[0][i] = 1;
            else
                break;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == -1){
                    cout << "jjjjjj" << endl;
                    continue;
                }
                else if (obstacleGrid[i-1][j] == -1 && obstacleGrid[i][j-1] == -1){
                    obstacleGrid[i][j] = -1;
                }
                else if (obstacleGrid[i-1][j] == -1){
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                } else if (obstacleGrid[i][j-1] == -1){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                }
                else{
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        for (const auto &item : obstacleGrid){
            for (const auto &i : item){
                cout << i << "," ;
            }
            cout << endl;
        }
        return obstacleGrid.back().back()>0 ? obstacleGrid.back().back():0;
    }
};
#endif //P10_P63_路径规划_有障碍物_H
