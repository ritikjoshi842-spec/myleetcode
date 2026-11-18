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
    void dfs(vector<vector<char>>& board, vector<vector<int>>& color, int i, int j, int n, int m, int c){
        color[i][j]= c;
        for(int k = 0; k < 4; k++){
            int row = i + x[k];
            int col = j + y[k];
            if((valid(row, col, n, m)) and (board[row][col]== 'O') and (color[row][col]==-1)){
                dfs(board, color, row, col, n, m, c);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int c = 0;
        vector<vector<int>> color(n, vector<int>(m, -1));
        for(int j = 0; j< m; j++){
            if((color[0][j]== -1) and (board[0][j]=='O')){
                dfs(board, color, 0, j, n, m, c);
            }
        }
        for(int i = 0; i< n; i++){
            if((color[i][m-1]== -1) and (board[i][m-1]== 'O')){
                dfs(board, color, i, m-1, n, m, 0);
            }
        }
        for(int j = 0; j< m; j++){
            if(color[n-1][j]==-1 and (board[n-1][j]== 'O')){
                dfs(board, color, n-1, j, n, m, c);
            }
        }
        for(int i = 0; i< n; i++){
            if(color[i][0]== -1 and (board[i][0]== 'O')){
                dfs(board, color, i, 0, n, m, c);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if((board[i][j]== 'O') and (color[i][j]== -1)){
                  board[i][j] = 'X';
                }
            }
        }
    }
};