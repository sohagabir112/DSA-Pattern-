/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res = NULL;
    void fun(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return;
        }

        if(root == p || root == q){
            res = root;
            return;
        }
        if(p->val > q->val){
            swap(p,q);
        }
        if(root->val < p->val){
            fun(root->right, p, q);
        }
        else if(root->val > q->val){
            fun(root->left, p, q);
        }
        else{
            res = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root, p, q);
        return res;
    }
};