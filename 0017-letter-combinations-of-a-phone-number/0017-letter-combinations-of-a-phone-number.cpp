class Solution {
public:
    void fx(vector<string> &res, unordered_map<char, string> &mp, int idx, string &digits,
    string &temp){
        if(idx== digits.size()){
            res.push_back(temp);
            return;
        }
        string output = mp[digits[idx]];
        for(int i=0; i< output.size(); i++){
            temp.push_back(output[i]);
            fx(res, mp, idx+ 1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char, string> mp;
        string temp;
        mp['2']= "abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5']= "jkl";
        mp['6']= "mno";
        mp['7']= "pqrs";
        mp['8']= "tuv";
        mp['9']= "wxyz";
        fx(res, mp, 0, digits, temp);
        return res;
    }
};