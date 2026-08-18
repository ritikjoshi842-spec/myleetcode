class Solution {
public:
    int check(vector<vector<int>> &matrix, int k, int guess){
        int rows= matrix.size();
        int cols = matrix.size();
        int row = rows - 1;
        int col = 0;
        int count = 0;
        while(row>= 0 and col< cols){
            if(matrix[row][col]<= guess){
               count = count + row + 1;
               col++; 
            }
            else{
                row--;
            }
        }
        return count; 
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int n = matrix.size() - 1;
       int low = matrix[0][0];
       int high = matrix[n][n];
       int res = 0;
       while(low<= high){
        int guess = low + (high - low)/2;
        if(check(matrix, k, guess)>= k){
           res= guess;
           high = guess - 1;
        }   
        else{
           low = guess + 1;
        }
       }
       return res;
    }
};