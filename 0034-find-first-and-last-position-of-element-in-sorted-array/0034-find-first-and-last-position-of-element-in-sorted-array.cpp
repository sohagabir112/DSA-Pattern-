class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res1 = -1 , res2 = -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid] < target){
                int mid = (low + high) / 2;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                res1 = mid;
                high = mid - 1;
            }
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                res2 = mid;
                low = mid + 1;
            }
        }
        return {res1, res2};
    }
};