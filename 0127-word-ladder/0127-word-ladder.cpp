class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        queue<pair<string, int>> q;
        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]] = 1;
        }
        if(mp.find(beginWord)== mp.end()){
            mp[beginWord] = 1;
        }
        if(mp.find(endWord)== mp.end()){
            return 0;
        }
        q.push({beginWord, 1});
        mp.erase(beginWord);
        while(!q.empty()){
            string s = q.front().first;
            int val = q.front().second;
            q.pop();
            if(s== endWord){
                return val;
            }
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                for(int j = 97; j <= 122; j++){
                    s[i] = j;
                    if(mp.find(s)!= mp.end()){
                      q.push({s, val+1});
                      mp.erase(s);  
                    }
                    s[i] = c;
                }
            }
        }
        return 0;
    }
};