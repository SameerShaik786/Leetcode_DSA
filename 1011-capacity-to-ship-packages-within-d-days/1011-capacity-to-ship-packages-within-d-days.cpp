class Solution {
public:
    bool isPossible(int weight,vector<int> &weights,int days){
            int sum = 0;
            int no_of_days = 1;
            for(auto i: weights){
                if(sum + i <= weight){
                    sum += i;
                }
                else{
                    no_of_days++;
                    sum = i;
                }
            }
            return no_of_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1,high = 0;
        for(auto i: weights){
            high += i;
            low = max(low,i);
        }
        int ans = INT_MAX;
        while( low <= high){
            int mid = (low + high)/2;
            if(isPossible(mid,weights,days)){
                cout<<mid<<endl;
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