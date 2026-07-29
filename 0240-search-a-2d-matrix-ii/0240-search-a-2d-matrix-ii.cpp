class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;

        while(row>=0 && col<m){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                row--;
            }
            else{
                col++;
            }
        }

        // for(int i=0;i<n;i++){
        //     int low =0;
        //     int high = m-1;
        //     while(low <= high){
        //         int mid = (low+high)/2;

        //         if(matrix[i][mid] == target){
        //             return true;
        //         }
        //         else if(matrix[i][mid] < target){
        //             low = mid + 1;
        //         }
        //         else{
        //             high = mid - 1; 
        //         }
        //     }
        // }
        
        return false;
    }
};