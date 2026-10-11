class Solution {
public:
    int strStr(string haystack, string needle) {
        int win = needle.size();
        int start = 0;
        int end = win - 1;

        while(end< haystack.size()){
            if(haystack.substr(start, win)== needle){
                return start;
            }
            start++;
            end++;
        }
        return -1;
    }
};