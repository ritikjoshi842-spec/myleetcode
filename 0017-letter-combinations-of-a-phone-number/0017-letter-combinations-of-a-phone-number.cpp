class Solution {
public:
    void f(vector<string> &res, unordered_map<char, string> &mp, int idx, int n, string digits, string &s){
        if(idx== n){
           res.push_back(s);
           return;
        }
        string temp= mp[digits[idx]];
        for(int i=0; i< mp[digits[idx]].size(); i++){
            s.push_back(temp[i]);
            f(res, mp, idx+ 1, n, digits, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string> res;
       unordered_map<char, string> mp;
       mp['2']= "abc";
       mp['3']= "def";
       mp['4']= "ghi";
       mp['5']= "jkl";
       mp['6']= "mno";
       mp['7']= "pqrs";
       mp['8']= "tuv";
       mp['9']= "wxyz";
       string s= "";
       f(res, mp, 0, digits.size(), digits, s);
       return res;
    }
};