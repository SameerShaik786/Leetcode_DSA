class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
              prefix[i] = prefix[i-1]+nums[i];
        }
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i=0;i<n;i++){
            int  rem=prefix[i]%k ;
            if(m.find(rem) != m.end()){
                if(i-m[rem] >= 2){
                    return true;
                }
            }
            else{
                m[rem] = i;
            }
        }
        return false;
    }
};