class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0, n = nums.size();
        sort(nums.begin(),nums.end());
        while(i < n-2){
            int sum = nums[i];
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int j = i+1, k = n-1;
            while(j < k){
                int secondSum = nums[j]+nums[k];
                int target = -nums[i];
                if(secondSum + sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if(secondSum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;
        }
        return ans;
    }
};