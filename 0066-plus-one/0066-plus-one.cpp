class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int start= digits.size()- 1;
       vector<int> res;
       int carry= 0;
       while(start>= 0){
        digits[start]++;
        if(start== 0 and digits[start]== 10){
           res.push_back(0);
           res.push_back(1); 
        }
        else if(digits[start]<10){
            res.push_back(digits[start]);
            for(int i= start- 1; i>= 0; i--){
                res.push_back(digits[i]);
            }
            break;
        }
        else{
            res.push_back(0);
            carry= 1;
        }
        start--;
       }
       reverse(res.begin(), res.end()); 
       return res;
    }
};