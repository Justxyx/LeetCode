//
// Created by 肖应雄 on 2022/3/17.
//

#ifndef P7_P_559_N叉树_递归求深度_H
#define P7_P_559_N叉树_递归求深度_H

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        vector<Node*> v = root->children;
        int maxLen = 1;
        for (Node *item : v){
            int len =1 + maxDepth(item);
            if (len > maxLen) maxLen = len;
        }
        return maxLen;
    }
};
#endif //P7_P_559_N叉树_递归求深度_H
