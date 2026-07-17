class Solution {
public:
bool found= false;
    bool isPossible(vector<vector<char>>& board, int rows, int cols, int i){
        for(int j=0; j< 9; j++){
            if(board[j][cols]== '0' + i){
                return false;
            }
        }
        for(int k=0; k< 9; k++){
            if(board[rows][k]== '0' + i){
                return false;
            }
        }
        int row= (rows/3)* 3;
        int col= (cols/3)* 3;
        for(int j= row; j< row+ 3; j++){
            for(int k= col; k< col+3; k++){
                if(board[j][k]== '0' + i){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board, int rows, int cols){
        if(rows== 9){
            found = true;
            return;
        }
        if(cols== 9){
            solve(board, rows + 1, 0);
            return;
        }
        if(board[rows][cols]!= '.'){
            solve(board, rows, cols + 1);
            return;
        }
        for(int i=1; i<= 9; i++){
            if(isPossible(board, rows, cols, i)== true){
                board[rows][cols]= '0'+ i;
                solve(board, rows, cols+ 1);
                if(found== true){
                    return;
                }
                board[rows][cols]= '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int rows= 0;
        int cols= 0;
        solve(board, rows, cols);
    }
};