class Solution {
public:
    int maxDepth(string s) {
       int count = 0;
       int max_count = 0;
       for(int i = 0; i< s.size(); i++){
        if(s[i]== '('){
            count++;
            max_count =  max(count, max_count);
        }
        else if(s[i]== ')'){
           count--; 
        }
        else{

        }
       }
       return max_count;
    }
};