class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int i=0,n = nums.size(),j=0;
        vector<int> ans;
        while(j<n){
            pq.push({nums[j],j});

            while(!pq.empty() && !(j-pq.top().second <= k-1)){
                pq.pop();
            }

            if(j >= k-1){
                if(!pq.empty()){
                    ans.push_back(pq.top().first);
                }
            }
            j++;
        }
        return ans;
    }
};