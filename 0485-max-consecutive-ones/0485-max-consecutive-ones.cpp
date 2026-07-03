class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i=0,j=0,n=nums.size();
        while(j < n){
           if(nums[j]==0){
            i = j+1;
           }
           ans = max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};