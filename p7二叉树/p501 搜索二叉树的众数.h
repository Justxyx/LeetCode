//
// Created by 肖应雄 on 2022/4/11.
//

#ifndef P7_P501_搜索二叉树的众数_H
#define P7_P501_搜索二叉树的众数_H


class Solution {
public:

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        vector<int> res2;
        find(root,res);
        int maxCount = 1;
        int count = 0;
        vector<int>::iterator p1 = res.begin();
        vector<int>::iterator p2 = p1;
        while (p2 != res.end()){
            if (*p1 == *p2){
                ++ count;
                if (count > maxCount){
                    res2.clear();
                    res2.push_back(*p2);
                    maxCount = count;
                } else if (count == maxCount){
                    res2.push_back(*p2);
                }
                ++ p2;
            } else{
                count = 1;
                if (count == maxCount)
                    res2.push_back(*p2);
                p1 = p2;
                ++ p2;
            }
        }

        return res2;
    }

    void find(TreeNode *node,vector<int> &res){
        if (node == nullptr)
            return;
        find(node->left,res);
        res.push_back(node->val);
        find(node->right,res);
        return;

    }
};
#endif //P7_P501_搜索二叉树的众数_H
