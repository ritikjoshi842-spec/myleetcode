
class Solution {
public:

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return (a.first * a.first + a.second * a.second) < 
                   (b.first * b.first + b.second * b.second);
        }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
       for(int i=0; i<k; i++){
        pair<int, int> curr= {points[i][0], points[i][1]};
        pq.push(curr);
       }
       for(int j=k; j< points.size(); j++){
         int x= pq.top().first* pq.top().first;
         int y= pq.top().second* pq.top().second;
         if((points[j][0]* points[j][0] + points[j][1]* points[j][1])< x + y){
            pq.pop();
            pq.push({points[j][0], points[j][1]});
         }
       }
       vector<vector<int>> res;
       while(!pq.empty()){
        auto curr= {pq.top().first, pq.top().second};
        res.push_back(curr);
        pq.pop();
       }
       return res;
    }
};