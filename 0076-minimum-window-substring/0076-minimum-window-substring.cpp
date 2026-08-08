class Solution {
public:
    bool fx(int have[256], int needed[256]){
        for(int i=0; i< 256; i++){
            if(have[i]< needed[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0;
        int high = 0;
        int have[256]= {0};
        int needed[256]= {0};
        for(int i=0; i< t.size(); i++){
            needed[t[i]]++;
        }
        int start = 0;
        int minlen = INT_MAX;
        for(int high = 0; high < s.size(); high++){
            have[s[high]]++;
            while(fx(have, needed)){
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