class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, int n){
        int rows= row;
        int cols= col;
        for(int i=0; i< cols; i++){
            if(board[rows][i]== 'Q'){
                return false;
            }
        }
        rows= row;
        cols= col;
        for(int i=0; i< rows; i++){
            if(board[i][cols]== 'Q'){
               return false;
            }
        }
        rows= row;
        cols= col;
        while(rows>= 0 and cols>= 0){
            if(board[rows][cols]== 'Q'){
                return false;
            }
            rows--;
            cols--;
        }
        rows= row;
        cols= col;
        while(rows>= 0 and cols< n){
            if(board[rows][cols]== 'Q'){
                return false;
            }
            rows--;
            cols++;
        }
        return true;
    }
    void f(vector<vector<char>> &board, int row, int n, int &count){
        if(row== n){
            count++;
            return;
        }
        for(int col=0; col< n; col++){
            if(isSafe(board, row, col, n)== true){
                board[row][col]= 'Q';
                f(board, row+1, n, count);
                board[row][col]= '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int count= 0;
        f(board, 0, n, count);
        return count;
    }
};