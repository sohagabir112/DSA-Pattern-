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
    vector<int> arr;
    void fun(TreeNode* root){
        if(root == NULL){
            return;
        }
        fun(root->left);
        arr.push_back(root->val);
        fun(root->right);

        return;
    }
    bool findTarget(TreeNode* root, int k) {
        fun(root);

        int n = arr.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(arr[i] + arr[j] == k){
                return true;
                break;
            }
            if(arr[i] + arr[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};