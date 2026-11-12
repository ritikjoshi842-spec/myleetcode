class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
       vector<int> left;
       vector<int> right;
       stack<int> st;
       for(int i = n - 1; i>= 0; i--){
        while((!st.empty()) and (arr[st.top()]>= arr[i])){
            st.pop();
        }
        if(st.empty()){
            right.push_back(n);
        }
        else{
            right.push_back(st.top());
        }
        st.push(i);
       }
       while(!st.empty()){
        st.pop();
       }
       for(int i = 0; i< n; i++){
        while((!st.empty()) and (arr[st.top()]> arr[i])){
            st.pop();
        }
        if(st.empty()){
            left.push_back(-1);
        }
        else{
            left.push_back(st.top());
        }
        st.push(i);
       }
       reverse(right.begin(), right.end());
       long long ans = 0;
       for(int i = 0; i < n; i++){
        long long x = i - left[i];
        long long y = right[i]- i;
        ans = ans + (1LL * x * y * arr[i])% 1000000007;
       }
       int res = 0;
       res = ans% 1000000007;
       return res;
    }
};