class Solution {
public:
bool check(vector<int> &nums, int k, int guess){
    int ans = 0;
    int count = 1;
    for(int i=0; i< nums.size(); i++){
        if(ans + nums[i]<= guess){
            ans= ans + nums[i];
        }
        else{
            ans= nums[i];
            count++;
        }
    }
    if(count<= k){
        return true;
    }
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i< nums.size(); i++){
            sum = sum + nums[i];
        }
        int high= sum;
        int res= -1;
        while(low<= high){
            int guess= low + (high - low)/2;
            if(check(nums, k, guess)){
                high= guess - 1;
                res= guess;
            }
            else{
                low = guess + 1;
            }
        }
        return res;
    }
};