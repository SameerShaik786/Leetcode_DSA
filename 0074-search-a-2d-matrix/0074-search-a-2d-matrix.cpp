class Solution {
public:
    bool isPossible(vector<vector<int>> &matrix,int row,int target){
        int low = 0,high = matrix[0].size();
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0,high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] <= target && target<=matrix[mid][n-1]){
                if(isPossible(matrix,mid,target)){
                    return true;
                }
                return false;
            }
            else if(matrix[mid][0] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};