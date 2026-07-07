class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int i=0, n = intervals.size();
        while(i < n){
            int j = i+1;
            int start = intervals[i][0];
            int end = intervals[i][1];
            int count = 0;
            while(j<n && end >= intervals[j][0]){
                    end = max(end,intervals[j][1]);
                    j++;
                    count++;
            }
            ans.push_back({start,end});
            if(count == 0){
                i++;
            }
            else{
                i+= count+1;
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans = intervals;
        int n = ans.size();
        ans.push_back({newInterval[0],newInterval[1]});
        sort(ans.begin(),ans.end());
        return merge(ans);
    }
};