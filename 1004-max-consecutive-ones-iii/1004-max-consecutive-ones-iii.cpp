class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),zeros_flipped = 0;
        int ans = 0;
        while(j<n){
            if(nums[j]==0) zeros_flipped++;
            while(i<n && zeros_flipped > k){
                if(nums[i]==0){
                    zeros_flipped--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};