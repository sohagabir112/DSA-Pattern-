class Solution {
public:
    void fun(vector<int>&a, int n, int idx,  int sum, int target, vector<int>&dairy, vector<vector<int>>&res){
        if(idx == n){
            if(sum == target){
                res.push_back(dairy);
            }
            return;
        }

        fun(a, n, idx+1, sum, target, dairy, res);

        if(a[idx] + sum <= target){
            dairy.push_back(a[idx]);
            sum += a[idx];
            fun(a, n, idx, sum, target, dairy, res);
            dairy.pop_back();
            sum -= a[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        int idx = 0;
        vector<int> dairy;
        vector<vector<int>> res;
        fun(candidates, n, idx, sum, target, dairy, res);
        
        return res;
    }
};