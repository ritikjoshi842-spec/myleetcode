class Solution {
public:
    int solve(int m, int n, int guess){
        int row= m;
        int col= 1;
        int count = 0;
        while(row> 0 and col<= n){
            if(row* col <= guess){
                count= count + row;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
      int low= 1;
      int high= m*n;
      int res= 0;
      while(low<= high){
        int mid= low + (high - low)/2;
        int count = solve(m, n, mid);
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