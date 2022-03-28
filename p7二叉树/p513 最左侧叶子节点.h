//
// Created by 肖应雄 on 2022/3/28.
//

#ifndef P7_P513_最左侧叶子节点_H
#define P7_P513_最左侧叶子节点_H

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int max = 0;
        while (!que.empty()){
            int size = que.size();
            max = que.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
        }
        return max;
    }
};
#endif //P7_P513_最左侧叶子节点_H
