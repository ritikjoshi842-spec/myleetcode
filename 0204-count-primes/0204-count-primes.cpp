class Solution {
public:
    int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        int sieve[n];
        for(int i = 0; i< n; i++){
            sieve[i] = 1;
        }
        sieve[1] = 0;
        sieve[0] = 0;
        for(int i = 2; i*i < n; i++){
         if(sieve[i]==1){
           for(int j = i*i; j< n; j = j + i){
            if(j%i==0){
              sieve[j] = 0;
            }
           }
         }
        }
        int count = 0;
        for(int i = 0; i< n; i++){
            if(sieve[i]==1){
                count++;
            }
        }
        return count;
    }
};