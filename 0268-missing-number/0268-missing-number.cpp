class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int high = nums.size();
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        int s = (high* (high + 1))/2;
        int ans = s - sum;
        return ans;
    }
};