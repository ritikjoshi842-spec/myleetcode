class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, -1, 1};
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
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i,
             int j, int n, int m, int& count) {
        visited[i][j] = true;
        count++;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if ((valid(row, col, n, m)) and (visited[row][col] == false) and
                (grid[row][col] == 1)) {
                dfs(grid, visited, row, col, n, m, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_count = 0;
        vector<vector<int>> visited(n, vector<int>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((visited[i][j] == false) and (grid[i][j] == 1)) {
                    int count = 0;
                    dfs(grid, visited, i, j, n, m, count);
                    max_count = max(count, max_count);
                }
            }
        }
        return max_count;
    }
};