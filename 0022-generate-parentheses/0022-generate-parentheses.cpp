class Solution {
public:
    vector<string> f(vector<string> &ans, string temp, int open, int close, int n){
        if(open== n and close== n){
          ans.push_back(temp);
        }
        if(open< n){
          temp.push_back('(');
          f(ans, temp, open+ 1, close, n);
          temp.pop_back();
        }
        if(close< open){
            temp.push_back(')');
            f(ans, temp, open, close+ 1, n);
            temp.pop_back();
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        return f(ans, temp, 0, 0, n);
    }
};