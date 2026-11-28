class Solution {
public:
int fx(int x){
    int sum = 0;
    while(x> 0){
      int digit = x%10;
      sum = sum + digit;
      x = x/10;  
    }

    return sum;
}
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums.size(); i++){
            sum1 = sum1 + nums[i];
            sum2 = sum2 + fx(nums[i]);
        }
        int ans = abs(sum1 - sum2);
        return ans;
    }
};