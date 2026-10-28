class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        prev[0] = nums[0];
        for(int i=1;i<n;i++){
            prev[i] = prev[i-1] + nums[i];
        }
        return prev;
    }
};