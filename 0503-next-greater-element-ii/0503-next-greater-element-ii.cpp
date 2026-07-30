class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size()- 1;
        stack<int> st;
        vector<int> res;
        for(int i= n-1; i>= 0; i--){
            st.push(nums[i]);
        }
        for(int i= n; i>= 0; i--){
             while(!st.empty() and st.top()<= nums[i]){
                st.pop();
            }
            if(st.empty()){
                res.push_back(-1);
            }
            else if(st.top()> nums[i]){
                res.push_back(st.top());           
            }
           
            st.push(nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};