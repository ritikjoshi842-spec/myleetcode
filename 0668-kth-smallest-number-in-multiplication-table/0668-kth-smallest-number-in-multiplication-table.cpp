class Solution {
public:
    int fx(int guess, int m, int n, int k){
        int start= m;
        int row = m;
        int col = 1;
        int count = 0;
        while(col <= n and row > 0){
            if(start<= guess){
                count = count + row;
                start = start + row;
                col++;
            }
            else{
                start = start - col;
                row--;
            }
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int res = 0;
        while(low <= high){
          int mid = low + (high - low)/2;
          int count = fx(mid, m, n, k);
          if(count>= k){
            res= mid;
            high = mid - 1;
          }
          else{
            low= mid + 1;
          } 
        }
        return res;
    }
};