//
// Created by 肖应雄 on 2022/5/26.
//

#ifndef P9_P968_H
#define P9_P968_H

class Solution {
public:
    int count = 0;
    int minCameraCover(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        recur(root);
        if (root->val == 0){
            if (root->left != nullptr && root->right != nullptr ){
                if (root->left->val != 1 && root->right->val != 1){
                    ++ count;
                }
            } else if (root->left != nullptr && root->left->val != 1)
                ++ count;
            else if (root->right != nullptr && root->right->val != 1)
                ++ count;
            else{

            }
        }
        return count;
    }

    /*
     * 原始 0
     * 叶子节点  -1
     * 摄像头 1
     * 被覆盖 2
     */
    void recur(TreeNode *node){
        if (node == nullptr)
            return;
        recur(node->left);
        recur(node->right);
        // 叶子节点
        if (node->left == nullptr && node->right == nullptr){
            node->val = -1;
            return;
        }
        // 孩子节点有叶节点 必为摄像头
        if ((node->left != nullptr && node->left->val == -1) || (node->right != nullptr && node->right->val == -1)){
            node->val = 1;
            ++ count;
            if (node->left != nullptr && node->left->val == 0)
                node->left->val = 2;
            if (node->right != nullptr && node->right->val == 0)
                node->right->val = 2;
            return;
        }

        // 孩子节点有0
        if (node->left != nullptr && node->left->val == 0){
            if (node->left->left != nullptr && node->left->left->val == 1)
                node->left->val = 2;
            else if (node->left->right != nullptr && node->left->right->val == 1)
                node->left->val = 2;
            else{
                node->val = 1;
                ++count;
                node->left->val = 2;
                if (node->right != nullptr)
                    node->right->val = 2;
            }
        }
        if (node->right != nullptr && node->right->val == 0){
            if (node->right->left != nullptr && node->right->left->val == 1)
                node->right->val = 2;
            else if (node->right->right != nullptr && node->right->right->val == 1)
                node->right->val = 2;
            else{
                node->val = 1;
                ++count;
                node->right->val = 2;
                if (node->left != nullptr)
                    node->left->val = 2;
            }
        }
    }

};
#endif //P9_P968_H
