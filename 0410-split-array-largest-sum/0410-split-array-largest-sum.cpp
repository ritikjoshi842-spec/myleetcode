class Solution {
public:
    bool fx(int mid, vector<int> nums, int k){
        int count = 1;
        int distribute= 0;
        for(int i=0; i< nums.size(); i++){
            if(distribute + nums[i]<= mid){
                distribute= distribute + nums[i];
            }
            else{
                count++;
                distribute= nums[i];
            }
        }
        if(count<= k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(), nums.end());
        int high= 0;
        for(int i=0; i< nums.size(); i++){
            high= high + nums[i];
        }
        int res= 0;
        while(low<= high){
            int mid= low + (high - low)/2;
            if(fx(mid, nums, k)== true){
                res= mid;
                high= mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};