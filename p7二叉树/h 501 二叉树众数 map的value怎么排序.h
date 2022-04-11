//
// Created by 肖应雄 on 2022/4/11.
//
/*
 * 这是一道挺好的题目的 有空看看
 */
#ifndef P7_H_501_二叉树众数_MAP的VALUE怎么排序_H
#define P7_H_501_二叉树众数_MAP的VALUE怎么排序_H


class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> bank;
        find(root,bank);
        unordered_map<int,int> resMap;
        for (const auto &item : bank){
            resMap[item] ++;
        }
        /*
         * map 没有 value 排序
         * 其实有两个问题不太理解
         *      1. compare 为什么要static？
         */

        vector<pair<int,int>> vectorMap(resMap.begin(),resMap.end());
        std::sort(vectorMap.begin(), vectorMap.end(), compare);
        vector<int> res;
        for (int i = 0; i < vectorMap.size(); ++i) {
            if (vectorMap[i].second == vectorMap[0].second)
                res.push_back(vectorMap[i].first);
            else
                break;
        }
        return res;
    }

    bool static compare(const pair<int,int> p1,const pair<int,int> p2){
        return p1.second > p2.second;
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
#endif //P7_H_501_二叉树众数_MAP的VALUE怎么排序_H
