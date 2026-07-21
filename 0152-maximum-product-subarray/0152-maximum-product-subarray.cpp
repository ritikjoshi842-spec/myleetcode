class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct= nums[0];
        int minproduct= nums[0];
        int res= nums[0];
        for(int i= 1; i< nums.size(); i++){
            int v1= nums[i];
            int v2= minproduct* nums[i];
            int v3= maxproduct* nums[i];
            maxproduct= max(v1, max(v2, v3));
            minproduct= min(v2, min(v1, v3));
            res= max(res, max(maxproduct, minproduct));
        } 
        return res;  
    }
};