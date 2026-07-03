class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int left = 0,right = 0,n= nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        while(right < n){
            m[nums[right]]++;
            while(left < n && m.size() > 2){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    m.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};