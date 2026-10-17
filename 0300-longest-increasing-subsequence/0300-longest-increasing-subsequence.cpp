class Solution {
public:
    int fun(vector<int>&a, int n, int i, int prev, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }

        int c1 = 0;
        if(prev == -1 || a[i] > a[prev]){
            c1 = 1 + fun(a, n, i+1, i, dp);
        }
        int c2 = fun(a, n, i+1, prev, dp);

        return dp[i][prev+1] = max(c1, c2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(n+1, -1));

        return fun(nums, n, 0, -1, dp);
    }
};