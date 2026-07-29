class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> arr(101, 0);
        for(int i=0; i< nums.size(); i++){
            arr[nums[i]]++;
        }
        for(int i=0; i< arr.size(); i++){
            if(arr[i]> 2){
                return false;
            }
        }
        return true;
    }
};