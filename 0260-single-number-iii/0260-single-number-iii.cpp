class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++){
            x = x ^ nums[i];
        }
        int i;
        for(i = 0; i < 32; i++){
           if((x & (1<<i))!= 0){
            break;
           } 
        }
        int grp1 = 0;
        int grp2 = 0;
        for(int j = 0; j< nums.size(); j++){
          if((nums[j] & (1<<i))== 0){
            grp1 = grp1 ^ nums[j];
          }  
          else{
            grp2 = grp2 ^ nums[j];
          }
        }
        vector<int> res;
        res.push_back(grp1);
        res.push_back(grp2);
        return res;
    }
};