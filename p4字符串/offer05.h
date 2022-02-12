class Solution {
public:
    string replaceSpace(string s) {
        list<char> list;
        for (const auto &item : s){
            if ( item == ' '){
                list.push_back('%');
                list.push_back('2');
                list.push_back('0');
            } else{
                list.push_back(item);
            }
        }

        for (const auto &item : list)
            cout << item << endl;
        return string (list.begin(),list.end());
    }
};