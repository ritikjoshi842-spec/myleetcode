class Solution {
public:
    int solve(vector<vector<int>> &matrix, int k, int target){
        int rows= matrix.size();
        int cols= matrix.size();
        int row = rows- 1;
        int col= 0;
        int count= 0;
        while(row>= 0 and col< cols){
            if(matrix[row][col]<= target){
                count= count + row + 1;
                col++;
            }
            else if(matrix[row][col]> target){
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int n= matrix.size()- 1;
        int high = matrix[n][n];
        int res= 0;
        while(low<= high){
            int mid = low + (high - low)/2;
            int count = solve(matrix, k, mid);
            if(count>= k){
                res= mid;
                high= mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};