class Solution {
public:
    
    double myPow(double x, int n) {
       long long power = n;
       long double base = x;
       if(power< 0){
        base= 1.0/base;
        power = -power;
       }
       double ans = 1.00;
       while(power> 0){
        if(power%2== 0){
            base = base* base;
            power = power/2;
        }
        else{
            ans = ans* base;
            power--;
        }
       }
       return ans;
    }
};