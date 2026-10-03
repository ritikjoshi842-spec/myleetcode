class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> mp;
        for(int i = 0; i< emails.size(); i++){
            string s = emails[i];
            string temp;
           for(int j = 0; j< s.size(); j++){
            if(s[j]=='@'){
               while(j< s.size()){
                temp.push_back(s[j]);
                j++;
               }
               mp[temp]++;
               break;
            }
            else if(s[j]== '.'){
               continue;
            }
            else if(s[j]== '+'){
                while(s[j]!= '@'){
                    j++;
                }
                while(j< s.size()){
                    temp.push_back(s[j]);
                    j++;
                }
                mp[temp]++;
                break;
            }
            else{
                temp.push_back(s[j]);
            }
           }
        }
        return mp.size();
    }
};