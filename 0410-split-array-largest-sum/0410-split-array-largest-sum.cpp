class Solution {
public:
    bool isPossible(int mid,vector<int> &nums,int k){
        int count = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int low = *max_element(nums.begin(),nums.end()),high = 0;
        for(int i=0;i<nums.size();i++){
            high += nums[i];
        }
        int ans = -1;
        while( low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};