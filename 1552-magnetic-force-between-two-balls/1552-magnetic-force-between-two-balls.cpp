class Solution {
public:
    bool isPossible(int mid,vector<int> &position, int m){
        int last = position[0];
        int count = 1;
        for(int i=1;i<position.size();i++){
            if(position[i]-last >= mid){
                count++;
                last = position[i];
            }
            if(count >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxi = position[0],mini = position[0];
        for(int i=1;i<position.size();i++){
            maxi = max(maxi,position[i]);
            mini = min(mini,position[i]);
        }
        int low = 1,high = maxi-mini;
        int ans = INT_MAX;
        while( low <= high){
            int mid = (low+high)/2;
            if(isPossible(mid,position,m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};