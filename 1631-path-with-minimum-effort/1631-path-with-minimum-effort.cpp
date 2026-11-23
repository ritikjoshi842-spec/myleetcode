class Solution {
public:
bool valid(int i, int j, int n, int m){
    if(i<0 or j<0){
        return false;
    }
    if(i>=n or j>=m){
        return false;
    }
    return true;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n==1 and m==1){
            return 0;
        }
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        while(!pq.empty()){
            int d = pq.top().first;
            auto info = pq.top().second;
            int r = info.first;
            int c = info.second;
            pq.pop();
            if(d> res[r][c]){
                continue;
            }
            for(int k= 0; k< 4; k++){
                int row = r + x[k];
                int col = c + y[k];
                if(!valid(row, col, n, m)){
                    continue;
                }
                int absdiff = abs(heights[row][col]- heights[r][c]);
                int newweight = max(absdiff, d);
                if(newweight< res[row][col]){
                    res[row][col] = newweight;
                    pq.push({newweight, {row, col}});
                }
            }
        }
        return res[n-1][m-1];
    }
};