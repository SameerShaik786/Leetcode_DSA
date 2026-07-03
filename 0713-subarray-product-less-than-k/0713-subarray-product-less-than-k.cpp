class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), i = 0,j=0;
        int ans =0;
        long long prod = 1;
        while( j < n){
            prod *= nums[j];

            while( i<n && prod >= k){
                prod /= nums[i];
                i++;
            }

            ans += j-i+1;
            j++;
        }
        return ans;
    }
};