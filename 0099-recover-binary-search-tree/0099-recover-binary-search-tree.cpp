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
    // void fun(TreeNode* root, vector<int> &arr){
    //     if(root == NULL){
    //         return;
    //     }

    //     fun(root->left, arr);
    //     arr.push_back(root->val);
    //     fun(root->right, arr);

    //     return;
    // }

    // void change(TreeNode* root, int a, int b){
    //     if(root == NULL){
    //         return;
    //     }

    //     if(root->val == a){
    //         root->val = b;
    //     }
    //     else if(root->val == b){
    //         root->val = a;
    //     }

    //     change(root->left, a, b);
    //     change(root->right, a, b);

    //     return;
    // }

    TreeNode* prev = NULL;
    TreeNode* w1first = NULL;
    TreeNode* w1second = NULL;
    TreeNode* w2first = NULL;
    TreeNode* w2second = NULL;
    int wrong = 0;

    void fun(TreeNode* root){
        if(root == NULL){
            return;
        }
        fun(root->left);

        if(prev == NULL){
            prev = root;
        }
        else{
            if(root->val < prev->val){
                if(wrong == 0){
                    w1first = prev;
                    w1second = root;
                    wrong++;
                }
                else{
                    w2first = prev;
                    w2second = root;
                    wrong++;
                }
            }
            prev = root;
        }
        
        fun(root->right);

        return; 
    }

    void recoverTree(TreeNode* root) {
        // vector<int>arr;
        // fun(root, arr);

        // int wrong = 0;
        // int w1first, w1second, w2first, w2second;
        // int n = arr.size();

        // for(int i=0;i<n-1;i++){
        //     if(arr[i] > arr[i+1]){
        //         if(wrong == 0){
        //             w1first = arr[i];
        //             w1second = arr[i+1];
        //             wrong++;
        //         }
        //         else{
        //             w2first = arr[i];
        //             w2second = arr[i+1];
        //             wrong++;
        //         }
        //     }
        // }
        // if(wrong == 1){
        //     change(root, w1first, w1second);
        // }
        // else{
        //     change(root, w1first, w2second);
        // }

        // return;

        fun(root);

        if(wrong == 1){
            swap(w1first->val, w1second->val);
        }
        else{
            swap(w1first->val, w2second->val);
        }

        return;
    }
};

const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}