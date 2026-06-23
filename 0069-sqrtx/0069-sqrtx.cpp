class Solution {
public:
    int mySqrt(int x) {
        long long left =1,right = x;
        int ans = -1;
        if(x == 0) return 0;
        while(left <= right){
            long long mid = (left+right)/2;
            if(mid*mid <= x){
                left = mid+1;
                ans = mid;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};