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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;

        while(!q.empty()){
            int levSize = q.size();
            vector<int>tmp(levSize);

            int first = 0;
            int last = levSize - 1;

            while(levSize--){
                TreeNode* t = q.front();
                q.pop();

                if(leftToright == 1){
                    tmp[first] = t->val;
                    first++;
                }
                else{
                    tmp[last] = t->val;
                    last--;
                }

                if(t->left != NULL){
                    q.push(t->left);
                }
                if(t->right != NULL){
                    q.push(t->right);
                }
                
            }
            res.push_back(tmp);
            leftToright = !leftToright;
        }
        return res;
    }
};