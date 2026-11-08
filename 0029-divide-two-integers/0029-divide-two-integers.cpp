class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend==INT_MIN and divisor==-1){
        return INT_MAX;
       }
       if(divisor==1){
        return dividend;
       }
       long long x = abs((long long)dividend);
       long long y = abs((long long)divisor);
       long long count = 0;
       while(x>= y){
         x = x - y;
         count++;
       }
       if(dividend< 0 and divisor< 0){
        return count;
       } 
       if(dividend<0 or divisor< 0){
        return -count;
       }
       return count;
    }
};