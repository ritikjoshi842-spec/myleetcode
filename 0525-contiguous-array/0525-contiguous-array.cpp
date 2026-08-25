class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int, int> mp;
       int prefix_sum = 0;
       int mxlen = 0;
       mp[0]= -1;
       for(int i = 0; i< nums.size(); i++){
        if(nums[i]== 0){
            prefix_sum--;
        }
        else{
            prefix_sum++;
        }
        if(mp.find(prefix_sum)!= mp.end()){
            int len = i - mp[prefix_sum];
            mxlen = max(len, mxlen);
        }
        else{
            mp[prefix_sum]= i;
        }
       }
       return mxlen;
    }
};