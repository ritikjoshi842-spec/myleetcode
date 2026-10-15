class Solution {
public:
    int reverse(int x) {
        long long rev= 0;
        while(x!= 0){
            rev= x%10+ rev*10;
            x= x/10;  
        }
        if(rev> INT_MAX or rev< INT_MIN){
            return 0;
        }
        return rev;
    }
};