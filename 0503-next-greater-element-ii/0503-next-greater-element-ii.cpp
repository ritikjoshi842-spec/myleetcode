class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        for(int i = nums.size() - 1; i>= 0; i--){
            st.push(nums[i]);
        }
        vector<int> res;
        int n = nums.size() - 1;
        for(int i = n; i>= 0 ; i--){
            if(st.empty()){
                res.push_back(-1);
                st.push(nums[i]);
            }
            while(!st.empty() and st.top()<= nums[i]){
                st.pop();
            }
            if(st.empty()){
                res.push_back(-1);
                st.push(nums[i]);
            }
            else if(st.top()> nums[i]){
                res.push_back(st.top());
                st.push(nums[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};