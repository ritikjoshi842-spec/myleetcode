class Solution {
public:
bool fx(string &s){
    int low = 0;
    int high = s.size()- 1;
    while(low< high){
        if(s[low]!= s[high]){
          return false;
        }
        low++;
        high--;
    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i< words.size(); i++){
            if(fx(words[i])){
                return words[i];
            }
        }
        return "";
    }
};