class Solution {
public:
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, -1, 1};
int valid(int i, int j, int n, int m){
    if(i< 0){
        return false;
    }
    if(j< 0){
        return false;
    }
    if(i>= n){
        return false;
    }
    if(j>= m){
        return false;
    }
    return true;
}

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j]== 2){
                    q.push({i, j});
                    grid[i][j] = -1;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        while(!q.empty() and fresh> 0){
            time++;
            int s = q.size();
            
            while(s--){
                pair<int, int> temp = q.front();
                q.pop();
                int r = temp.first;
                int c = temp.second;
                for(int k= 0; k< 4; k++){
                    int row = r + x[k];
                    int col = c + y[k];

                    if(valid(row, col, n, m) and (grid[row][col]!= 2) and (grid[row][col]!= -1) and (grid[row][col]!= 0)){
                        q.push({row, col});
                        grid[row][col] = -1;
                        fresh--;
                    }
                }
            }
        }
        if(fresh> 0){
            return -1;
        }
        return time;
    }
};