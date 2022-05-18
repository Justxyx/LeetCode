#include <iostream>
using namespace std;
#include <vector>
//#include <numeric>
#include <algorithm>
#include <map>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(),com);
        int count = 1;
        int left = points[0][0];
        int right = points[0][1];
        for (const auto &item : points){


            if (item[0] > right){
                ++ count;
                left = item[0];
                right = item[1];
            }

            if (item[0] > left)
                    left = item[0];
            if (item[1] < right)
                    right = item[1];

        }
        return count;
    }

    static bool com(vector<int> r1,vector<int> r2){
        return (r2[0] > r1[0]);
    }
};

int main() {
    vector<int> v1{1,0,2};
//    vector<int> v2{3,4,5,1,2};

    vector<vector<int>> v{{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    vector<vector<int>> v2{{4289383,51220269},{81692777,96329692},{57747793,81986128},{19885386,69645878},{96516649,186158070},{25202362,75692389},{83368690,85888749},{44897763,112411689},{65180540,105563966},{4089172,7544908}};
    Solution solution;
    cout << solution.findMinArrowShots(v2);
}
