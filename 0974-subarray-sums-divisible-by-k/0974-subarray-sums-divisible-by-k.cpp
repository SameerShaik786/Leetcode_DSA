class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), i = 0,j = 0;
        vector<int> prefix(n,0);
        prefix[i] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        unordered_map<int,int> m;
        m[0] = 1;
        int count = 0;
        for(int i=0;i<n;i++){
             int prev_rem = ((prefix[i] % k) + k) % k;
            if(m.find(prev_rem) != m.end()){
                count+=m[prev_rem];
                cout<<count<<endl;
            }
            m[prev_rem]++;
        }
        return count;
    }
};