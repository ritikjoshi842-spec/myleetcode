class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(), nums.end());
     vector<vector<int>> res;
     for(int i = 0; i< nums.size()- 2; i++){
        if(i> 0 and nums[i]== nums[i- 1]){
            continue;
        }
        int low = i+ 1;
        int high = nums.size() - 1;
        while(low < high){
        int sum = nums[low] + nums[high] + nums[i];
        if(sum == 0){
            res.push_back({nums[i], nums[low], nums[high]});
            while(low< high and nums[low]== nums[low + 1]){
                low++;
            }
            while(low< high and nums[high]== nums[high - 1]){
                high--;
            }
            low++;
            high--;
        }
        else if(sum< 0){
            low++;
        }
        else{
            high--;
        }
        }
     }
     return res;
    }
};