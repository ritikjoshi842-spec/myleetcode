class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char, int> mp;
    mp['I']= 1;
    mp['V']= 5;
    mp['X']= 10; 
    mp['L']= 50;
    mp['C']= 100;
    mp['D']= 500;
    mp['M'] = 1000;
       int sum = 0;
       int i = 0;
       while(i< s.size()- 1){
         if((s[i]== 'I') and (s[i+1]== 'V')){
            sum = sum + 4;
            i= i+2;
         } 
         else if((s[i]== 'I') and (s[i+1]== 'X')){
            sum = sum + 9;
            i= i+2;
         }
         else if((s[i]== 'X') and (s[i+1]== 'L')){
            sum= sum + 40;
            i= i+2;
         }
         else if((s[i]== 'X') and (s[i+1]== 'C')){
            sum = sum + 90;
            i= i+2;
         }
         else if((s[i]== 'C') and (s[i+1]== 'D')){
            sum = sum + 400;
            i= i+2;
         }
         else if((s[i]== 'C') and (s[i+1]== 'M')){
            sum= sum + 900;
            i=i+2;
         }
         else{
            sum = sum + mp[s[i]];
            i++;
         }
       }
       if(i== (s.size()- 1)){
        sum = sum + mp[s[i]];
       } 
       return sum;
    }
};