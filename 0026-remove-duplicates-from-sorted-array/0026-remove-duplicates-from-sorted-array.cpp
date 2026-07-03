class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 , k=1, j=1;
        int n = nums.size();
        while(j<n){
            if(nums[j] == nums[j-1]){
                j++;
                continue;
            }
            else{
                nums[i+1]=nums[j];
                k++;
                i++;
                j++;
            }
        }
        return k;
    }
};