class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> unlock;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lock;
        int n= capital.size();
        for(int i=0; i< n; i++){
            if(capital[i]<= w){
                unlock.push({profits[i], capital[i]});
            }
            else{
                lock.push({capital[i], profits[i]});
            }
        }
        while(k>0){
            if(unlock.empty()){
                break;
            }
            auto temp= unlock.top();
            w= w + temp.first;
            unlock.pop();
            k--;
            while(!lock.empty() and w>= lock.top().first){
               auto x= lock.top();
               unlock.push({x.second, x.first});
               lock.pop();
            }
        }
        return w;
    }
};