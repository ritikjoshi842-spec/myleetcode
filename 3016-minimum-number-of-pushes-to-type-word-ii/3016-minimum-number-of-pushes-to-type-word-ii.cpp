class Solution {
public:
    int minimumPushes(string word) {
       priority_queue<pair<int, char>> pq;
       unordered_map<char, int> mp;
       for(int i=0; i< word.size(); i++){
          mp[word[i]]++;
       } 
       for(auto i: mp){
        pq.push({i.second, i.first});
       }
       int count = 1;
       int res= 0;
       while(!pq.empty()){
        if(count<= 8){
            res= res + pq.top().first;
            pq.pop();
        }
        else if(count > 8 and count<= 16){
            res= res + pq.top().first* 2;
            pq.pop();
        }
        else if(count> 16 and count<= 24){
            res= res + pq.top().first* 3;
            pq.pop();
        }
        else{
            res= res + pq.top().first* 4;
            pq.pop();
        }
        count++;
       }
       return res;
    }
};