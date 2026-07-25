class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int power = 0;
        int nopower = arr[0];
        int res = arr[0];

        for(int i=1;i<n;i++){
            int v1 = arr[i];
            int v2 = nopower + arr[i];
            int v3 = power + arr[i];
            int v4 = nopower;

            res = max(res,max(max(v1,v2), max(v3,v4)));
            
            nopower = max(v1,v2);
            power = max(v3,v4);
        }
        return res;

        // int noDelete = arr[0];
        // int oneDelete = INT_MIN;
        // int ans = arr[0];

        // for(int i=1;i<n;i++){
        //     int prevNodelete =  noDelete;
        //     int prevOnedelete = oneDelete;

        //     noDelete = max(prevNodelete+arr[i], arr[i]);
            
        //     if(prevOnedelete == INT_MIN){
        //         oneDelete = prevNodelete;
        //     }
        //     else{
        //         int v2 = prevOnedelete + arr[i];
        //         oneDelete = max(v2, prevNodelete);
        //     }
        //     ans = max(ans, max(oneDelete, noDelete));
        // }
        // return ans;
    }
};