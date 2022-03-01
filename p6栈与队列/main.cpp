#include <iostream>
#include <stack>
using namespace std;
#include <queue>

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (stack.size() == 0)
                stack.push(s[i]);
            else{
                if (stack.top() == s[i]){
                    stack.pop();
                } else{
                    stack.push(s[i]);
                }
            }
        }
        return string((&stack.top() + 1 - stack.size()),(&stack.top() + 1));
    }
};


int main() {
    Solution solution;
    cout <<  solution.removeDuplicates("ttqamlonsmhqdbripqacpqiigbaiicascmgppljcpdsjjfirkrtdrkslbfplmhtbskptranqrdfqhbrmemdeepogmptpnmpclqofgkdrnrhojietiodmplcrgjiieroidcbmcbgpgijgoajjhcmtmbfipsirrksdrjbnnabmeapredageictokcpmlnhqdsokaresichmsekbhsjpfireoqciotrjhkhehdmtnrtbnbcpajmblhmmbikhjdiapgrhkijkdicqfjreitkjaprmphjolndfdgekotqfrmtacgkbjthqetpctceanjtthhejogjgnkbkfsgcanhjnqtqoppckgpesdnjgkdcnromjbetbfcmfkalaiplkbigsqlrdskfgnjnojaiehqodeitjqgmfcjljngbtmidtoglildbaibkeppibabamitbpckgjrsagebgqkjnchnighobtsjhcmcbkmllsmgdflssjebgodqnlpaqahmopbnpifnttqamlonsmhqdbripqacpqiigbaiicascmgppljcpdsjjfirkrtdrkslbfplmhtbskptranqrdfqhbrmemdeepogmptpnmpclqofgkdrnrhojietiodmplcrgjiieroidcbmcbgpgijgoajjhcmtmbfipsirrksdrjbnnabmeapredageictokcpmlnhqdsokaresichmsekbhsjpfireoqciotrjhkhehdmtnrtbnbcpajmblhmmbikhjdiapgrhkijkdicqfjreitkjaprmphjolndfdgekotqfrmtacgkbjthqetpctceanjtthhejogjgnkbkfsgcanhjnqtqoppckgpesdnjgkdcnromjbetbfcmfkalaiplkbigsqlrdskfgnjnojaiehqodeitjqgmfcjljngbtmidtoglildbaibkeppibabamitbpckgjrsagebgqkjnchnighobtsjhcmcbkmllsmgdflssjebgodqnlpaqahmopbnpifn");
}
