struct cmp{
    bool operator()(pair<int, string> &a, pair<int, string> &b){
        if(a.first!= b.first){
            return a.first> b.first;
        }
        return a.second< b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(int i=0; i< words.size(); i++){
            mp[words[i]]++;
        }
        for(auto i: mp){
            string word= i.first;
            int freq= i.second;
            pair<int, string> curr= {freq, word};
            if(pq.size()< k){
                pq.push(curr);
            }
            else if(curr.first> pq.top().first or 
            (curr.first== pq.top().first and curr.second< pq.top().second)){
                pq.pop();
                pq.push(curr);
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};