struct cmp{
    bool operator()(pair<int, char> &a, pair<int, char> &b){
        if(a.first!= b.first){
            return a.first< b.first;
        }
        return a.second< b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>, vector<pair <int, char>>, cmp> pq;
        for(int i=0; i< s.size(); i++){
            mp[s[i]]++;
        }
        for(auto i: mp){
            char ch= i.first;
            int freq= i.second;
            pair<int, char> curr= {freq, ch};
            pq.push(curr);
        }
        string res= "";
        int idx= 0;
        while(!pq.empty()){
            if(idx== 0 or res[idx- 1]!= pq.top().second){
                pair<int, char> p1= {pq.top().first, pq.top().second};
                res.push_back(pq.top().second);
                p1.first--;
                if(p1.first> 0){
                    pq.push(p1);
                }
                pq.pop();
            }
            else{
                pair<int, char> curr= {pq.top().first, pq.top().second};
                pq.pop();
                if(pq.empty()){
                    return "";
                }
                pair<int, char> p2= {pq.top().first, pq.top().second};
                res.push_back(p2.second);
                pq.pop();
                p2.first--;
                if(p2.first> 0){
                    pq.push(p2);
                }
                pq.push(curr);
            }
            idx++;
        }
        return res;
    }
};