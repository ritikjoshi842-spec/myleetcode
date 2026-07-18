class Solution {
public:
    void solve(vector<int> &temp, vector<vector<int>> &res, vector<int> &nums, int idx){
        if(idx== nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(temp, res, nums, idx + 1);
        temp.pop_back();
        while(idx< nums.size()- 1 and nums[idx]== nums[idx + 1]){
            idx++;
        }
        solve(temp, res, nums, idx + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> temp;
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      solve(temp, res, nums, 0);
      return res;  
    }
};