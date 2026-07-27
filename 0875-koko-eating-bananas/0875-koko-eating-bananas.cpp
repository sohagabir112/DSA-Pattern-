class Solution {
public:
    long long fun(vector<int>&piles, int speed, int n){
        long long h = 0;
        for(int i=0;i<n;i++){
            h = h + piles[i] /speed;
            if(piles[i]%speed != 0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>high){
                high = piles[i];
            }
        }
        int res = -1;
        while(low<=high){
            int mid = (low+high)/2;
            long long hours = fun(piles,mid,n);

            if(hours>h){
                low = mid + 1;
            }
            else{
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};