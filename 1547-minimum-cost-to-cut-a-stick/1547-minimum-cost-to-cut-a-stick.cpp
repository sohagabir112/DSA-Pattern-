class Solution {
public:
    int fun(vector<int>&cuts,  int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int res = INT_MAX;
        
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1];
            int r = cost + fun(cuts, i, k-1, dp) + fun(cuts, k+1, j, dp);
            res = min(res, r);
        }
        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int>c;
        c.push_back(0);
        for(int i=0;i<cuts.size();i++){
            c.push_back(cuts[i]);
        }
        c.push_back(n);

        sort(c.begin(), c.end());
        int s = c.size();
        vector<vector<int>> dp(s, vector<int>(s, -1));
        return fun(c, 1, s-2, dp);
    }
};