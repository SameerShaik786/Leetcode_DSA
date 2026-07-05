class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low = 0,high = arr.size()-1;
        int floor_val=-1,ceil_val=-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                floor_val = mid;
                high = mid-1;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        low = 0,high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                ceil_val = mid;
                low = mid+1;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {floor_val,ceil_val};
    }
};