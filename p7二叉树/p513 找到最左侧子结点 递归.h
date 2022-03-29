//
// Created by 肖应雄 on 2022/3/29.
//

#ifndef P7_P513_找到最左侧子结点_递归_H
#define P7_P513_找到最左侧子结点_递归_H

class Solution {
public:
    int maxLen = INT_MIN;
    int max;
    int findBottomLeftValue(TreeNode* root) {
        find(root,0);
        return max;
    }

    void find(TreeNode *node,int curLen){
        if (node->left == nullptr && node->right == nullptr){ // 先序遍历，同层第一个遍历到的结点一定是最左侧结点
            if (curLen > maxLen){
                max = node->val;
                maxLen = curLen;
            }
            return;
        }

        if (node->left){
            curLen ++;
            find(node->left,curLen);
            curLen --;
        }

        if (node->right){
            curLen ++;
            find(node->right,curLen);
            curLen --;
        }
        return;
    }
};

#endif //P7_P513_找到最左侧子结点_递归_H
