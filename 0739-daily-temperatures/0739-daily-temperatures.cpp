class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<int> st;
       int n= temperatures.size()- 1;
       vector<int> res;
       res.push_back(0);
       st.push(n);
       for(int i= n- 1; i>= 0; i--){
        while(!st.empty() and temperatures[st.top()]<= temperatures[i]){
            st.pop();
        }
        if(st.empty()){
            res.push_back(0);
        }
        else{
            res.push_back(st.top()- i);
        }
        st.push(i);
       }
       reverse(res.begin(), res.end());
       return res;
    }
};