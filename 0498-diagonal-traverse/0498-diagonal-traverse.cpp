class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n + m - 1);
        for(int i = 0; i < n; i++){
           for(int j = 0; j< m; j++){
            temp[i + j].push_back(mat[i][j]);
           }
        }
        vector<int> res;
        int count = 0;
        for(int i = 0; i< temp.size(); i++){
           if(count%2== 0){
            reverse(temp[i].begin(), temp[i].end());
            for(int j = 0; j< temp[i].size(); j++){
                res.push_back(temp[i][j]);
            }
           } 
           else{
            for(int j = 0; j < temp[i].size(); j++){
                res.push_back(temp[i][j]);
            }
           }
           count++;
        }
        return res;
    }
};