class Solution {
public:
    int countTriples(int n) {
    int count= 0;
      for(int i=1; i<= n; i++){
        int low= 1;
        int high= i-1;
        while(low< high){
            if((low* low + high* high)== i*i){
               count++;
               low++;
               high--;
            }
            else if((low* low + high* high)> i*i){
                high--;
            }
            else{
                low++;
            }
        }
      }
      return count*2;
    }
};