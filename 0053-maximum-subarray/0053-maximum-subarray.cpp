class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for(int i = 1; i< nums.size(); i++){
            int v1= nums[i];
            int v2= nums[i] + sum;
            max_sum = max(max(v1, v2), max_sum);
            sum = max(v1, v2);
        }
        return max_sum;
    }
};