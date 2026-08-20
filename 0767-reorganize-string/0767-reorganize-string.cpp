class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i< s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto i: mp){
           pq.push({i.second, i.first});
        }
        string res;
        while(pq.size()>= 2){
           auto temp1= pq.top();
           res.push_back(temp1.second);
           pq.pop();
           auto temp2= pq.top();
           res.push_back(temp2.second);
           pq.pop();
           if(temp1.first> 1){
            pq.push({temp1.first - 1, temp1.second});
           }
           if(temp2.first> 1){
            pq.push({temp2.first - 1, temp2.second});
           }
        }
        if(pq.size()== 1){
            if(pq.top().first== 1){
                res.push_back(pq.top().second);
            }
            else{
                return "";
            }
        }
        return res;
    }
};