class Solution {
public:
void f(vector<int> &candidates, int target, vector<vector<int>> &res, int idx, int sum, vector<int> &temp){
    if(sum== target){
        res.push_back(temp);
        return;
    }
    if(sum > target or idx== candidates.size()){
        return;
    }
    f(candidates, target, res, idx+1, sum, temp);
    temp.push_back(candidates[idx]);
    f(candidates, target, res, idx, sum + candidates[idx], temp);
    temp.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        f(candidates, target, res, 0, 0, temp);
        return res;
    }
};