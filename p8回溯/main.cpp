#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>
#include <set>



class Solution1 {
public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> path;
        vector<vector<string>> res;
        int len = tickets.size()+1;
        backtracking(tickets,path,res,len);

//        if (res.size() > 1){
//            std::sort(res.begin(), res.end(), cmp);
//        }
        if (res.size() == 0)
            return path;
        return res[0];
    }

   static bool cmp(vector<string> &s1, vector<string> &s2) { //提供比较函数
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i])
                continue;
            else if (s1[i] > s2[i]){
                return true;
            } else{
                return false;
            }
        }
       return true;
    }

    void backtracking(vector<vector<string>> &tickets, vector<string> &path,vector<vector<string>> &res,int len){
        if (path.size() == len){
            if (res.empty()){
                res.push_back(path);
            } else{
                if (cmp(res[0],path)){
                    res.pop_back();
                    res.push_back(path);
                }
            }
            return;
        }

        for (int i = 0; i < tickets.size(); ++i) {
            // path == 0
            if (path.empty()){
                if (tickets[i][0] == "JFK"){
                    path.push_back(tickets[i][0]);
                    path.push_back(tickets[i][1]);
                    vector<vector<string>> tic = tickets;
                    try {
                        tic.erase(std::find(tic.begin(), tic.end(), tic[i]));
                    }catch (exception &e){
                        cout << "---" << endl;
                    }
                    backtracking(tic,path,res,len);
                    path.pop_back();
                    path.pop_back();
                } else{
                    continue;
                }
            } else{
                // 不为空
                string city = *(path.end()-1);
                if (tickets[i][0] == city){
                    path.push_back(tickets[i][1]);
                    vector<vector<string>> tic = tickets;
                    tic.erase(std::find(tic.begin(), tic.end(), tic[i]));
                    backtracking(tic,path,res,len);
                    path.pop_back();
                }
            }
        }
        return;
    }
};

class Solution2 {
public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        int resCity = -1;
        while (!tickets.empty()){
            if (res.empty()){
                for (int i = 0; i < tickets.size(); ++i) {
                    if (tickets[i][0] == "JFK"){
                        if (resCity == -1)
                            resCity = i;
                        else if (tickets[i][1]<tickets[resCity][1]){
                            resCity = i;
                        }
                    }
                }
                res.push_back(tickets[resCity][0]);
                res.push_back(tickets[resCity][1]);
                tickets.erase(std::find(tickets.begin(), tickets.end(), tickets[resCity]));
                resCity = -1;
                continue;
            } else{
                string nextCity = *(res.end()-1);
                for (int i = 0; i < tickets.size(); ++i) {
                    if (tickets[i][0] == nextCity){
                        if (resCity == -1)
                            resCity = i;
                        else if (tickets[i][1]<tickets[resCity][1]){
                            resCity = i;
                        }
                    }
                }
                res.push_back(tickets[resCity][1]);
                tickets.erase(std::find(tickets.begin(), tickets.end(), tickets[resCity]));
                resCity = -1;
                continue;
            }

        }
        return res;
    }
};



int main() {


    vector<vector<string>> tickets = {{"EZE","TIA"},{"EZE","AXA"},{"AUA","EZE"},{"EZE","JFK"},{"JFK","ANU"},{"JFK","ANU"},{"AXA","TIA"},{"JFK","AUA"},{"TIA","JFK"},{"ANU","EZE"},{"ANU","EZE"},{"TIA","AUA"}};
    vector<vector<string>> tics = {{"JFK","STL"},{"JFK","ALO"},{"JFK","EES"}};
    Solution solution;
    vector<string>res = solution.findItinerary(tics);
    for (const auto &item : res)
        cout << item << endl;

//
//    Solution solution;
//   vector<string> res = solution.findItinerary(tickets);
//    for (const auto &item : res)
//        cout << item << endl;

}
