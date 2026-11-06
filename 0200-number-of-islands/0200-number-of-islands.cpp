class Solution {
public:
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
bool valid(int i, int j, int n, int m){
            if(i<0 or i>=n or j<0 or j>=m){
                return false;
            }
            return true;
        }
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int row = i + x[k];
        int col = j + y[k];
        if(valid(row, col, n, m) and vis[row][col]== 0 and grid[row][col]== '1'){
            dfs(grid, vis, row, col, n, m);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<bool>> vis(n, vector<bool>(m, 0)); 
       int res = 0;
       for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(vis[i][j]== 0 and grid[i][j]=='1'){
                dfs(grid, vis, i, j, n, m);
                res++;
            }
        }
       }
       return res;
    }
};