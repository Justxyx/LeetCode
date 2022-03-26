//
// Created by 肖应雄 on 2022/3/26.
//



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<string> vec;
        solut(root,res,vec);
        return res;
    }

    void solut(TreeNode *node,vector<string> &res,vector<string> &vec){

        vec.push_back(to_string(node->val));
        if (node->left == nullptr && node->right == nullptr){
            string str = "";
            for (int i = 0; i < vec.size() - 1; ++i) {
                str += vec[i];
                str += "->";
            }
            str += vec[vec.size()-1] ;
            res.push_back(str);
        }
        if (node->left != nullptr){
            solut(node->left,res,vec);
            vec.pop_back();
        }
        if (node->right != nullptr)
        {
            solut(node->right,res,vec);
            vec.pop_back();
        }
    }
};

