class Solution {
public:
    bool check(int have[], int needed[]){
        for(int i = 0; i< 256; i++){
            if(have[i] < needed[i]){
              return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int have[256]= {0};
        int needed[256]= {0};
        for(int i = 0 ; i< t.size(); i++){
            needed[t[i]]++;
        }
        int low = 0;
        int high = 0;
        int minlen = INT_MAX;
        int start= 0;
        for(int high = 0; high< s.size(); high++){
            have[s[high]]++;
            while(check(have, needed)){
                int len = high - low + 1;
                if(len< minlen){
                    minlen = len;
                    start= low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(minlen== INT_MAX){
            return "";
        }
        return s.substr(start, minlen);
    }
};