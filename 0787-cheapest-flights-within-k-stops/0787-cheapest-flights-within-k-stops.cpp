class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0; 
        for(int i = 0; i < k+1; i++){
            vector<int> temp = dis;
            for(int j = 0; j < flights.size(); j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];
                if(dis[s]!=INT_MAX and wt + dis[s]< temp[d]){
                    temp[d] = dis[s] + wt;
                }
            }
            dis = temp;
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};