class Solution {
public:
bool isSafe(vector<vector<char>> board, int x, int col, int n){
   int rows= x;
   int cols= col;
   for(int i=0; i< rows; i++){
    if(board[i][cols]== 'Q'){
        return false;
    }
   }
   rows= x;
   cols= col;
   for(int i=0; i< cols; i++){
    if(board[rows][i]== 'Q'){
        return false;
    }
   }
   rows= x;
   cols= col;
   while(rows>= 0 and cols>= 0){
    if(board[rows][cols]== 'Q'){
        return false;
    }
    rows--;
    cols--;
   }
   rows= x;
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
void f(vector<vector<string>> &res, int x, int n, vector<vector<char>> board){
    if(x== n){
     vector<string> temp;
     for(int i=0; i< n; i++){
        string s= "";
        for(int j=0; j< n; j++){
            s= s+ board[i][j];
        }
        temp.push_back(s);
     }
     res.push_back(temp);
     return;
    }
    for(int col=0; col< n; col++){
    if(isSafe(board, x, col, n)== true){
        board[x][col]= 'Q';
        f(res, x+1 , n, board);
        board[x][col]= '.';
    }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        f(res, 0, n, board);
        return res;
    }
};