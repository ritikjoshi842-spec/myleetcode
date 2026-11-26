class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int prefix = 1;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(prefix);
            prefix = prefix * nums[i];
        }
        int suffix = 1;
        for(int i = nums.size()-1; i>= 0; i--){
            res[i] = res[i] * suffix;
            suffix = suffix * nums[i];
        }
        return res;
    }
};