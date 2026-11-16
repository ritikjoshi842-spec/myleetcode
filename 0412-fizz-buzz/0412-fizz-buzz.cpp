class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        string fb = "FizzBuzz";
        string f = "Fizz";
        string b = "Buzz";
        for(int i = 1; i <= n; i++){
            if((i%3==0) and (i%5==0)){
                res.push_back(fb);
            }
            else if(i%3== 0){
                res.push_back(f);
            }
            else if(i%5== 0){
                res.push_back(b);
            }
            else{
                string x = to_string(i);
                res.push_back(x);
            }
        }
        return res;
    }
};