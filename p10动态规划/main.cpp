#include <iostream>
using namespace std;
#include <vector>
#include <math.h>


            /*
             *   10
             *   2  8   -> 16
             *   2 2 2 2 2 -> 32
             *   2 6 2 -> 24
             *
             *
             *   f2 = 1;  2
             *   f3 = 2;  3
             *   f4 = 4;  4
             *   f5 = 6;  6
             *   f6 = 9;  9
             *
             *   7 = 5 + 2 = 4 + 3 = 2 + 2 + 3 = 12
             *         10      12     12
             *   8 = 6 + 2 =8 * 2 = 18
             *   9 = 27
             *   10 = 7 + 3 = 36;
             *   11 = 54
             *   11
             */



int main() {
    Solution solution;
     cout << solution.integerBreak(10);
    return 0;
}

