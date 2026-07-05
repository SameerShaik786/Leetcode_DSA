class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            ans = min(ans,nums[mid]);
            if(nums[high] < nums[low]){
                if(nums[low] <= nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};