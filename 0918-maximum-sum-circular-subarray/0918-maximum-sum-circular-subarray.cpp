class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int curMax = nums[0];
        int minSum = nums[0];
        int curMin = nums[0];
        int totalSum = nums[0];
        
        for(int i=1;i<n;i++){
            curMax = max(nums[i], curMax+nums[i]);
            maxSum = max(maxSum,curMax);

            curMin = min(nums[i], curMin+nums[i]);
            minSum = min(minSum,curMin);

            totalSum = totalSum + nums[i];
        }

        return maxSum<0 ? maxSum : max(maxSum, totalSum-minSum);
    }
};