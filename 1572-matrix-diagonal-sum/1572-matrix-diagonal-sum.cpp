class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i = 0;
        int j = 0;
        int k = mat.size() - 1;
        while(i< mat.size() and j< mat.size() and k>= 0){
            sum = sum + mat[i][j] + mat[k][j];
            i++;
            j++;
            k--;
         }
        int n = mat.size();
        if(mat.size()%2 != 0){
            sum = sum - mat[n/2][n/2];
        }
        return sum;
    }
};