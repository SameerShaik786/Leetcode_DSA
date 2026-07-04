class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, minSum = INT_MAX, curMax = 0,curMin = 0;
        for(int i=0;i<n;i++){
            curMax = max(nums[i],curMax+nums[i]);
            maxSum = max(curMax,maxSum);

            curMin = min(nums[i],curMin+nums[i]);
            minSum = min(minSum,curMin);
        }
        return max(maxSum,abs(minSum));
    }
};