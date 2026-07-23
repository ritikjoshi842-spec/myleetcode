class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int count = 0;
        int fuel = startFuel;
        priority_queue<int> pq;
        int prev= 0;
        stations.push_back({target, 0});
        for(int i= 0; i< stations.size(); i++){
           int distance = stations[i][0] - prev;
           while(fuel< distance){
            if(pq.empty()){
                return -1;
            }
            else{
                fuel = fuel  + pq.top();
                pq.pop();
                count++;
            }
           }
           fuel = fuel - distance;
           pq.push(stations[i][1]);
           prev= stations[i][0];
        }
        return count;
    }
};