class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(k,nums)-atMost(k-1,nums);
    }
    int atMost(int k,vector<int> &nums){
        int i=0,j=0,n = nums.size();
        unordered_map<int,int> m;
        int count = 0;
        while( j < n){
            m[nums[j]]++;
            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
};