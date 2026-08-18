/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void fun(TreeNode* root, vector<int> &res){
    //     if(root == NULL){
    //         return;
    //     }
    //     fun(root->left,res);
    //     res.push_back(root->val);
    //     fun(root->right,res);

    //     return;
    // }

    TreeNode* prev = NULL;
    bool res = true;

    void fun(TreeNode* root){
        if(root == NULL){
            return;
        }

        fun(root->left);
        if(prev == NULL){
            prev = root;
        }
        else{
            if(root->val <= prev->val){
                res = false;
            }
            prev = root;
        }
        fun(root->right);
        
        return;
    }
    bool isValidBST(TreeNode* root) {
        // vector<int>res;
        // fun(root,res);
        // int n = res.size();

        // for(int i=0;i<n-1;i++){
        //     if(res[i] >= res[i+1]){
        //         return false;
        //     }
        // }
        // return true;

        fun(root);
        return res;
    }
};