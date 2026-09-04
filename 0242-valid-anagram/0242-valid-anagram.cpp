class Solution {
public:
    bool isAnagram(string s, string t) {
        int smap[256] = {0};
        int tmap[256] = {0};
        for(int i = 0; i< s.size(); i++){
            smap[s[i]]++;
        }
        for(int i = 0; i< t.size(); i++){
            tmap[t[i]]++;
        }
        for(int j = 0; j< 256; j++){
            if(smap[j]!= tmap[j]){
                return false;
            }
        }
        return true;
    }
};