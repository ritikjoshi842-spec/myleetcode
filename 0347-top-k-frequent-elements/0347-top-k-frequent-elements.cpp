struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first!= b.first){
            return a.first > b.first;
        }
        return a.first> b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair <int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> mp;
        for(int i=0; i< nums.size(); i++){
           mp[nums[i]]++;
        }
        for(auto i : mp){
            int frequency= i.second;
            int element=  i.first;
            pair<int, int> curr= {frequency, element};
            if(pq.size()< k){
                pq.push(curr);
            }
            else if(curr.first> pq.top().first){
                pq.pop();
                pq.push(curr);
            }
            else{
                
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};