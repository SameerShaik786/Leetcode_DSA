class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,n = nums.size(),j=0;
        vector<int> ans;
        while(j<n){
            while(!dq.empty() && !(j-dq.front() <= k-1)){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }

            dq.push_back(j);
            if(j >= k-1){
                if(!dq.empty()){
                    ans.push_back(nums[dq.front()]);
                }
            }
            j++;
        }
        return ans;
    }
};