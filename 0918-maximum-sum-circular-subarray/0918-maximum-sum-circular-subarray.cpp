class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMax = 0, currMin = 0, maxSum = INT_MIN, minSum = INT_MAX;
        int total = 0;
        for(int i=0;i<n;i++){
            currMax = max(nums[i],currMax+nums[i]);
            maxSum = max(maxSum,currMax);

            currMin = min(nums[i],currMin+nums[i]);
            minSum = min(minSum,currMin);
            total += nums[i];
        }
        if(maxSum < 0){
            return maxSum;
        }
        return max(total-minSum,maxSum);
    }
};