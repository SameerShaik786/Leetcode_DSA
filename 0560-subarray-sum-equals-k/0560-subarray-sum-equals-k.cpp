class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        int i=0, j = 0;
        prefix[0] = nums[0];
        int count = 0;
        unordered_map<int,int> m;
        if(prefix[0] == k) count++;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            if(prefix[i]==k) count++;
        }
        for(int i=0;i<n;i++){
             int prevPrefix = prefix[i]-k;
             if(m.find(prevPrefix) != m.end()){
                count+=m[prevPrefix];
             }
             m[prefix[i]]++;
        }
        return count;
    }
};