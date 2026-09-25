class Solution {
public:
   // unordered_map<int,int> dp;
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        int prev1 = 0;
        int prev2 = 1;
        int ans ;
        for(int i=2;i<=n;i++){
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }

        return ans;

        // if(n == 0 || n == 1){
        //     return n;
        // }

        // if(dp.find(n) != dp.end()){
        //     return dp[n];
        // }
        // int a1 = fib(n-1);
        // int a2 = fib(n-2);
        // int ans = a1 + a2;

        // dp[n] = ans;

        // return ans;
    }
};