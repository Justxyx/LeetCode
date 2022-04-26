//
// Created by 肖应雄 on 2022/4/26.
//

#ifndef P8_H_332_H
#define P8_H_332_H

class Solution {
public:
    vector<string> res;
    int len = 0;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        len = tickets.size() + 1;
        backtracking(tickets);
        return res;
    }



    int backtracking(vector<vector<string>> &tickets){
        if (res.size() > len)
            return 0;
        if (res.size() == len)
            return 1;

        //此一次 res为空
        if (res.empty()){
            vector<int> select;
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[i][0] == "JFK"){
                    if (select.empty()){
                        select.push_back(i);
                    } else{
                        int selectSize = select.size();
                        for (int j = 0; j < select.size(); ++j) {
                            if (tickets[i][1] < tickets[select[j]][1]){
                                select.insert(select.begin()+j,i);
                                break;
                            } else{
                                continue;
                            }
                        }
                        if (select.size() == selectSize){
                            select.push_back(i);
                        }
                    }
                }
            }

            for (const auto i : select) {
                res.push_back(tickets[i][0]);
                res.push_back(tickets[i][1]);
                vector<vector<string>> tick = tickets;
                tick.erase(std::find(tick.begin(), tick.end(), tick[i]));
                if (backtracking(tick)){
                    return 1;
                }
                res.pop_back();
                res.pop_back();
            }
        }
        // res不为空
        {
            string city = *(res.end()-1);
            vector<int> select;
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[i][0] == city){
//                    select.push_back(i);

                    int selectSize = select.size();
                    for (int j = 0; j < select.size(); ++j) {
                        if (tickets[i][1] < tickets[select[j]][1]){
                            select.insert(select.begin()+j,i);
                            break;
                        } else{
                            continue;
                        }
                    }
                    if (select.size() == selectSize){
                        select.push_back(i);
                    }
                }
            }

            for (const auto i : select) {
                res.push_back(tickets[i][1]);
                vector<vector<string>> tick = tickets;
                tick.erase(std::find(tick.begin(), tick.end(), tick[i]));
                int resBack = backtracking(tick);
                if (resBack){
                    return 1;
                } else{
                    res.pop_back();
                }
            }
        }
        return 0;
    }
};
#endif //P8_H_332_H
