class Solution {
public:
    int isPossible(int i,vector<int> &piles,int h){
        long long count = 0;
        for(int j=0;j<piles.size();j++){
            int first = piles[j]/i;
            int rem = piles[j]-first*i;
            count += first;
            count += (rem==0) ? 0 : 1;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            mini = min(mini,piles[i]);
            maxi = max(maxi,piles[i]);
        }
        int low = 1, high = maxi;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(isPossible(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};