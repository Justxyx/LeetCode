//
// Created by 肖应雄 on 2022/3/22.
//

#ifndef P7_H257_回溯_求所有节点路径_H
#define P7_H257_回溯_求所有节点路径_H

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {""};
        vector<string> vec;
        vector<int> path;
        res(root,vec,path);
        cout << vec[0] << endl;
        return vec;
    }

    void res(TreeNode *node,vector<string> &vec,vector<int> &path){
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr){
            cout << node->val << endl;
            // 叶子节点
            string str;
            for (int i = 0; i < path.size() - 1; ++i) {
                str += to_string(path[i]) + "->";
            }
            int index = path.size() - 1;

            str += to_string( path[index]) ;
            vec.push_back(str);
        }

        if (node->left){
            res(node->left,vec,path);
            path.pop_back();
        }

        if (node->right){
            res(node->right,vec,path);
            path.pop_back();
        }
    }
};
#endif //P7_H257_回溯_求所有节点路径_H
