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
    unordered_map<int, int> in;
    int idx;

    TreeNode* fun(vector<int>&inorder, vector<int>&postorder, int low, int high){
        if(low > high){
            return NULL;
        }

        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = in[node->val];

        node->right = fun(inorder, postorder, id+1, high);
        node->left = fun(inorder, postorder, low, id-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        for(int i=0;i<n;i++){
            in[inorder[i]] = i;
        }
        idx = n-1;
        return fun(inorder, postorder,0, n-1);
    }
};