class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long long left = 0,right = nums.size()-1;
        int floor_ans = -1;
        while(left <= right){
            long long mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] <= target){
                left = mid+1;
                floor_ans = mid;
            }
            else{
                right = mid-1;
            }
        }
        return floor_ans+1;
    }
};