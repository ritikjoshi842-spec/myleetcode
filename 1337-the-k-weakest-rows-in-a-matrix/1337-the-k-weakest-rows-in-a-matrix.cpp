class Solution {
public:
    int get_weak(vector<int> &temp){
        int low = 0;
        int high = temp.size()- 1;
        int ans = temp.size(); 
        while(low<= high){
          int mid = low + (high - low)/2;
          if(temp[mid]== 0){
            ans = mid;
            high = mid - 1;
          }
          else{
            low = mid + 1;
          }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = mat.size();
        for(int i = 0; i< n; i++){
            int x= get_weak(mat[i]);
            pq.push({x, i});
        }
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    } 
};