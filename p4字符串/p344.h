 
 /**
  * @brief 
  *   stl 还是很不熟练  要再看看cpp primer
  */
 
 class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size() - 1;
        int i = 0;
        while ( size > i){
            swap(s[i],s[size]);
            ++ i;
            -- size;
        }
        for (const auto &item : s)
            cout << item << endl;
    }
};
