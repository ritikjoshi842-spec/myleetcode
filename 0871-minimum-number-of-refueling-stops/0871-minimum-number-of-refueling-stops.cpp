class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long fuel= startFuel;
        int i=0;
        priority_queue<int> pq;
        int ans= 0;
        while(fuel< target){
            while(i< stations.size() and fuel>= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            fuel= fuel + pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};