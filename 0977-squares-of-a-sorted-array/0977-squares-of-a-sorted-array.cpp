class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        if(a.size() == 0){
            for(int i=0;i<n;i++){
                nums[i] *= nums[i];
            }
            return  nums;
        }
        else if(b.size() == 0){
            for(int i=0;i<n;i++){
                nums[i] *= nums[i];
            }
            reverse(nums.begin(),nums.end());

            return nums;
        }
        else{
            for(int i=0;i<a.size();i++){
                a[i] *=a[i];
            }
            for(int i=0;i<b.size();i++){
                b[i] *= b[i];
            }
            reverse(a.begin(),a.end());

            int i =0, j=0;
            int p = a.size();
            int q = b.size();
            vector<int> num(n);
            int idx = 0;
            while(i<p && j<q){
                if(a[i] <= b[j]){
                    num[idx] = a[i];
                    idx++;
                    i++;
                }
                else{
                    num[idx] = b[j];
                    idx++;
                    j++;
                }
            }
            while(i<p){
                num[idx] = a[i];
                idx++;
                i++;
            }
            while(j<q){
                num[idx] = b[j];
                idx++;
                j++;
            }
        return num;
        }
    }
};