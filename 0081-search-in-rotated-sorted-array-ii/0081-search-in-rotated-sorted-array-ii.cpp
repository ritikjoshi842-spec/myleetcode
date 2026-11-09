class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()- 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target== nums[mid]){
                return true;
            }
            if(nums[mid]== nums[low] && nums[mid]== nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[mid]>= nums[low]){

                //left half sorted
                if(nums[mid]< target){
                    low = mid + 1;
                }
                else{
                    if(target== nums[low]){
                        return true;
                    }
                    if(target> nums[low]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
            }
            else{
                //right half
                if(nums[mid]< target){
                    if(target== nums[high]){
                        return true;
                    }
                    if(target< nums[high]){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};