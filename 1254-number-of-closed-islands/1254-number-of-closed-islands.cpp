class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isSurrounded(int i, int j, int n, int m) {
        if (i == 0) {
            return false;
        }
        if (i == n - 1) {
            return false;
        }
        if (j == 0) {
            return false;
        }
        if (j == m - 1) {
            return false;
        }
        return true;
    }
    bool valid(int i, int j, int n, int m) {
        if (i < 0) {
            return false;
        }
        if (j < 0) {
            return false;
        }
        if (i >= n) {
            return false;
        }
        if (j >= m) {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
             int n, int m, bool& check) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if ((valid(row, col, n, m)) and (isSurrounded(row, col, n, m)) and
                (vis[row][col] == false) and (grid[row][col] == 0)) {
                dfs(grid, vis, row, col, n, m, check);
            }
            else if((valid(row, col, n, m)) and (!isSurrounded(row, col, n, m)) and (vis[row][col]== false) and (grid[row][col] == 0)){
                check = false;
            
            }
        }
    }
 int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((vis[i][j] == false) and (grid[i][j] == 0) and
                (isSurrounded(i, j, n, m))) {
                bool check = true;
                dfs(grid, vis, i, j, n, m, check);
                if (check == true) {
                    count++;
                }
            }
        }
    }
    return count;
}
};