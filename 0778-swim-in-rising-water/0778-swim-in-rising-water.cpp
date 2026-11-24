class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if (i < 0 or j < 0) {
            return false;
        }
        if (i >= n or j >= m) {
            return false;
        }
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        res[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            int dis = pq.top().first;
            auto naruto = pq.top().second;
            int r = naruto.first;
            int c = naruto.second;
            pq.pop();
            if (dis > res[r][c]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int row = r + x[i];
                int col = c + y[i];
                if(!valid(row, col, n, n)) {
                    continue;
                }
                
                int temp = max(grid[row][col], dis);
                if (temp < res[row][col]) {
                    res[row][col] = temp;
                    pq.push({temp, {row, col}});
                }
            }
        }
        return res[n - 1][n - 1];
    }
};