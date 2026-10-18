class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i< 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
               if(board[i][j]!= '.'){
                mp[board[i][j]]++;
               } 
            }
            for(auto i : mp){
                if(i.second> 1){
                    return false;
                }
            }
        }
        for(int i = 0; i< 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j< 9; j++){
                if(board[j][i]!= '.'){
                  mp[board[j][i]]++;  
                }
            }
            for(auto i : mp){
                if(i.second> 1){
                    return false;
                }
            }
        }
        for(int i = 0; i< 9; i = i + 3){
           for(int j = 0; j < 9; j = j + 3){
              unordered_map<char, int> mp;
              for(int r = i; r < i + 3; r++){
                for(int c = j; c < j + 3; c++){
                    if(board[r][c]!= '.'){
                        mp[board[r][c]]++;
                    }
                }
              }
              for(auto i : mp){
                    if(i.second> 1){
                        return false;
                    }
                }
           }
        }
        return true;
    }
};