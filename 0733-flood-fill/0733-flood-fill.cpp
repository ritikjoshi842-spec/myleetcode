class Solution {
public:
  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};
bool valid(int i, int j, int n, int m){
    if(i< 0){
        return false;
    }
    if(i>=n){
      return false;
    }
    if(j< 0){
        return false;
    }
    if(j>= m){
        return false;
    }
    return true;
}
void dfs(vector<vector<bool>> &vis, int n, int m, vector<vector<int>> &image, int color, int sr, int sc, int oldColor){
    vis[sr][sc] = true;
    image[sr][sc] = color;
    for(int k = 0; k< 4; k++){
        int row = sr + x[k];
        int col = sc + y[k];
        if(valid(row, col, n, m) and (vis[row][col]== false) and (oldColor == image[row][col])){
            dfs(vis, n, m, image, color, row, col, oldColor);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n = image.size();
       int m = image[0].size();
       vector<vector<bool>> vis(n, vector<bool> (m, false)); 
       dfs(vis, n, m, image, color, sr, sc, image[sr][sc]);
       return image;
    }
};