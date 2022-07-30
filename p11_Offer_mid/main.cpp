#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <queue>
#include <numeric>
using namespace std;
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
       mins.push_back(0);
       maxs.push_back(0);
    }

    void addNum(int num) {
        mins.push_back(num);
        minHeap();
        if (mins.size() > maxs.size())
        {
            maxs.push_back(mins[1]);
            swap(mins[1],mins.back());
            mins.resize(mins.size()-1);
            MaxHeap();
            minHeap();
        }
    }

    double findMedian() {
        vector<int> s = maxs;
        if (maxs.size() > mins.size())
            return maxs[1];
        double i = (maxs[1] + mins[1])/2.0;
        return i;
    }


    void test() {
        vector<int> &s = maxs;
        s = {1,2,3};
        MaxHeap();
        s[1];
    }

    void MaxHeap() {
        for (int i = maxs.size()/2; i > 0; --i) {
              adjust(true, i);
        }
    }
    void minHeap() {
        for (int i = mins.size()/2; i > 0; --i) {
            adjust(false, i);
        }
    }
    void adjust(bool b, int index) {
        int temp = 2 * index;
        if (b) {
            if (temp+1 < maxs.size() && maxs[temp+1] > maxs[temp])
                ++temp;
            if (maxs[index] > maxs[temp])
                return;
            swap(maxs[index], maxs[temp]);
            return;
        }
        if (!b) {
            if (temp+1 < maxs.size() && maxs[temp+1] < maxs[temp])
                ++temp;
            if (maxs[index] < maxs[temp])
                return;
            swap(maxs[index], maxs[temp]);
            return;
        }

    }
private:
    vector<int> mins;
    vector<int> maxs;
};



int main() {
    MedianFinder  m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() << endl;
}