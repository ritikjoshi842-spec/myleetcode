class Solution {
public:
    int f(vector<int> soldier){
        int low= 0;
        int high= soldier.size() - 1;
        int res= soldier.size();
        while(low<= high){
            int mid = low + (high- low)/2;
            if(soldier[mid]== 1){
                low= mid + 1;
            }
            else{
                res= mid;
                high= mid - 1;
            }
        }
        return res;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
     priority_queue<pair<int, int>> pq;
     for(int i=0; i< k; i++){
        int sold= f(mat[i]);
        pq.push({sold, i});
     } 
     for(int j=k; j< mat.size(); j++){
        int sold= f(mat[j]);
        pair<int, int> curr= {sold, j};
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