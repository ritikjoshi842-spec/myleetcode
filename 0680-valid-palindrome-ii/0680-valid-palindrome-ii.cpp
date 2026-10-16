class Solution {
public:
bool fx(int low, int high, string& s){
    while(low< high){
        if(s[low]== s[high]){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low< high){
            if(s[low]== s[high]){
                low++;
                high--;
            }
            else{
               if(fx(low+1, high, s) or fx(low, high-1, s)){
                return true;
               } 
               else{
                return false;
               }               
            }
        }
        return true;
    }
};