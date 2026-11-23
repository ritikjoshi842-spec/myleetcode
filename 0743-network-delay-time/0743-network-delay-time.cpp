class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int src = times[i][0];
            int dest = times[i][1];
            int wt = times[i][2];
            adj[src].push_back({dest, wt});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
          int d = pq.top().first;
          int x  = pq.top().second;
          pq.pop();
          if(d> distance[x]){
            continue;
          }
          for(int i = 0; i< adj[x].size(); i++){
            int neigh = adj[x][i].first;
            int dis = adj[x][i].second;
            if(d + dis< distance[neigh]){
              distance[neigh] = d + dis;
              pq.push({dis+d, neigh});
            }
          }
        }
        int ans = INT_MIN;
        for(int i = 1; i < distance.size(); i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};