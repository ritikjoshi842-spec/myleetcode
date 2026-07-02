class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> nums;
        for(int i=0; i< capital.size(); i++){
           nums.push_back({capital[i], profits[i]}); 
        }
        sort(nums.begin(), nums.end());
        priority_queue<int> pq;
        int idx= 0;
        for(int j=0; j< k; j++){
            while(idx< nums.size() and nums[idx].first<= w){
                pq.push(nums[idx].second);
                idx++;
            }
            if(pq.empty()){
                break;
            }
            w= w + pq.top();
            pq.pop();
        }
        return w;
    }
};