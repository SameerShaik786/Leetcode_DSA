class Solution {
public:
    bool isPossible(long long speed,vector<int> &dist, double hour){
        double no_of_hours = 0;
        int n = dist.size();
        for(int i=0;i<dist.size();i++){
            if(i == n-1){
                no_of_hours += (double)dist[i]/speed;
            }
            else{
                int first = dist[i]/speed;
                int rem = dist[i]-speed*first;
                no_of_hours += first;
                no_of_hours += (rem==0) ? 0 : 1;
            }
        }
        return no_of_hours <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long low = 1, high = INT_MAX;
        int ans = INT_MAX;
        while( low <= high){
            long long speed = (low + high)/2;
            if(isPossible(speed,dist,hour)){
                ans = speed;
                high = speed-1;
            }
            else{
                low = speed+1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};