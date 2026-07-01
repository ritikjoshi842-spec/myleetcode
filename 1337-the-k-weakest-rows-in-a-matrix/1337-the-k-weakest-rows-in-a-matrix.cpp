class Solution {
public:
    int check(int idx, vector<vector<int>> mat){
        int count = 0;
        for(int i=0; i< mat[0].size(); i++){
          if(mat[idx][i]== 1){
            count++;
          }
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       priority_queue<pair<int, int>> pq;
       for(int i=0; i< k; i++){
        pq.push({check(i, mat), i});
       }
       for(int i=k; i< mat.size(); i++){
        pair<int, int> curr= {check(i, mat), i};
        if(curr< pq.top()){
            pq.pop();
            pq.push(curr);
        }
       } 
       vector<int> res;
       while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
       }
       reverse(res.begin(), res.end());
       return res;
    }
};