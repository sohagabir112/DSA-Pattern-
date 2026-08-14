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
    // vector<int> arr;
    // void fun(TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     fun(root->left);
    //     arr.push_back(root->val);
    //     fun(root->right);

    //     return;
    // }

    stack<TreeNode*>asc;
    stack<TreeNode*>desc;

    TreeNode* getSmall(){
        if(asc.empty()){
            return NULL;
        }

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightchild = small->right;
        while(rightchild){
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small;
    }

    TreeNode* getBig(){
        if(desc.empty()){
            return NULL;
        }

        TreeNode* big = desc.top();
        desc.pop();

        TreeNode* leftchild = big->left;

        while(leftchild){
            desc.push(leftchild);
            leftchild = leftchild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
    //     fun(root);

    //     int n = arr.size();
    //     int i = 0;
    //     int j = n-1;
    //     while(i<j){
    //         if(arr[i] + arr[j] == k){
    //             return true;
    //             break;
    //         }
    //         if(arr[i] + arr[j] > k){
    //             j--;
    //         }
    //         else{
    //             i++;
    //         }
    //     }
    //     return false;
    // }

    if(root == NULL){
        return false;
    }

    TreeNode* t = root;
    while(t){
        asc.push(t);
        t = t->left;
    }

    t = root;
    while(t){
        desc.push(t);
        t = t->right;
    }

    TreeNode* i = getSmall();
    TreeNode* j = getBig();

    while(i && j && i != j && i->val <= j->val){
        int sum = i->val + j->val;

        if(sum == k){
            return true;
        }
        if(sum > k){
            j = getBig();
        }
        else{
            i = getSmall();
        }
    }
        return false;
    }
};