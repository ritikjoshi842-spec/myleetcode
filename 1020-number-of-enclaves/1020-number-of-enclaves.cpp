class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool touch(int i, int j, int n, int m) {
        if (i == 0) {
            return false;
        }
        if (j == 0) {
            return false;
        }
        if (i == n - 1) {
            return false;
        }
        if (j == m - 1) {
            return false;
        }
        return true;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid,
             vector<vector<bool>>& visited, bool& is_touch, int& count) {
        visited[i][j] = true;
        count++;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if ((touch(row, col, n, m)) and (visited[row][col] == false) and
                (grid[row][col] == 1)) {
                dfs(row, col, n, m, grid, visited, is_touch, count);
            } else if ((!touch(row, col, n, m)) and
                       (visited[row][col] == false) and (grid[row][col] == 1)) {
                is_touch = true;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int net_count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == false and (grid[i][j] == 1) and (touch(i, j, n, m))) {
                    int count = 0;
                    bool is_touch = false;
                    dfs(i, j, n, m, grid, visited, is_touch, count);
                    if (is_touch == false) {
                        net_count = net_count + count;
                    }
                }
            }
        }
        return net_count;
    }
};