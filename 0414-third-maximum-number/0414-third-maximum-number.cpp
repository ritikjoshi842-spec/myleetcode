class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest = LLONG_MIN;
        long long second_largest = LLONG_MIN;
        long long third_largest = LLONG_MIN;
        for(int i = 0; i< nums.size(); i++){
            if(largest< nums[i]){
                third_largest= second_largest;
                second_largest= largest;
                largest= nums[i];
            }
            else if(nums[i]> second_largest and nums[i]< largest){
                third_largest= second_largest;
                second_largest= nums[i];
            }
            else if(nums[i]> third_largest and nums[i]< second_largest){
                third_largest= nums[i];
            }
            else{

            }
        }
        if(second_largest== LLONG_MIN or third_largest== LLONG_MIN){
            return largest;
        }
        return third_largest;
    }
};