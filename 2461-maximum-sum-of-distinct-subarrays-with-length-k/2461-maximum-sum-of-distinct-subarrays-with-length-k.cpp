class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        long long sum = 0;
        while(j<n){
            sum += nums[j];
            m[nums[j]]++;
            while(i<n && j-i+1 > k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                sum-=nums[i];
                i++;
            }

            if(m.size()==k)
                ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};