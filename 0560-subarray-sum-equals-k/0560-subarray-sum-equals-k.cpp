class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix_sum = 0;
        int count = 0;
        mp[0]= 1;
        for(int i =0; i< nums.size(); i++){
            prefix_sum = prefix_sum + nums[i];
            if(mp.find(prefix_sum- k)!= mp.end()){
               count = count + mp[prefix_sum- k]; 
            }
            mp[prefix_sum]++;
        }
        return count;
    }
};