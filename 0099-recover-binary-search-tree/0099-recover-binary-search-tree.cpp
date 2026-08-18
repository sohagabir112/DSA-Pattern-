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
    void fun(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return;
        }

        fun(root->left, arr);
        arr.push_back(root->val);
        fun(root->right, arr);

        return;
    }

    void change(TreeNode* root, int a, int b){
        if(root == NULL){
            return;
        }

        if(root->val == a){
            root->val = b;
        }
        else if(root->val == b){
            root->val = a;
        }

        change(root->left, a, b);
        change(root->right, a, b);

        return;
    }

    void recoverTree(TreeNode* root) {
        vector<int>arr;
        fun(root, arr);

        int wrong = 0;
        int w1first, w1second, w2first, w2second;
        int n = arr.size();

        for(int i=0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                if(wrong == 0){
                    w1first = arr[i];
                    w1second = arr[i+1];
                    wrong++;
                }
                else{
                    w2first = arr[i];
                    w2second = arr[i+1];
                    wrong++;
                }
            }
        }
        if(wrong == 1){
            change(root, w1first, w1second);
        }
        else{
            change(root, w1first, w2second);
        }

        return;
    }
};