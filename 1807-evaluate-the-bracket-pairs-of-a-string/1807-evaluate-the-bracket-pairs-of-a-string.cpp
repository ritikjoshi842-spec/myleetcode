class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i  = 0; i< knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string res;
        int i = 0;
        while(i< s.size()){
            if(s[i]=='('){
              i++;
              string temp;
              while(s[i]!= ')'){
                temp.push_back(s[i]);
                i++;
              }
              if(mp.find(temp)!= mp.end()){
                    res.append(mp[temp]);
                }
              else{
                res.push_back('?');
              }
              i++;
            }
            else{
                res.push_back(s[i]);
                i++;
            }
        }
        return res;
    }
};