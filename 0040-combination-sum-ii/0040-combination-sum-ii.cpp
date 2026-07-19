class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int> &temp, vector<int> &candidates, int idx, int target){
         if(target== 0){
            res.push_back(temp);
            return;
         }
         if(target< 0){
           return; 
         }
         if(candidates.size()== idx){
            return;
         }
         temp.push_back(candidates[idx]);
         solve(res, temp, candidates, idx+ 1, target - candidates[idx]);
         temp.pop_back();
         while(idx< candidates.size()- 1 and candidates[idx]== candidates[idx+ 1]){
            idx++;
         }
         solve(res, temp, candidates, idx + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(res, temp, candidates, 0, target);
        return res;
    }
};