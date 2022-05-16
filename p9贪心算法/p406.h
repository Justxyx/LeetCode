//
// Created by 肖应雄 on 2022/5/16.
//

#ifndef P9_P406_H
#define P9_P406_H
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), comp);
        vector<vector<int>> res;
        int temp = people[0][0];
        int index = 0;
        for (int i = 0; i < people.size(); ++i) {
            index = people[i][1];
            res.insert(res.begin()+index,people[i]);
        }
        return res;
    }

    static bool comp(const vector<int> &r1,const vector<int> r2){
        if (r1[0] == r2[0])
            return r2[1] > r1[1];
        else
            return r2[0] < r1[0];
    }

};
#endif //P9_P406_H
