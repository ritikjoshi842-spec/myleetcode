class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char> st;
       if(k== num.size()){
        string s = "0";
        return s;
       }
       for(int i = 0; i< num.size(); i++){
        while(!st.empty() and k>0 and st.top()>num[i]){
            k--;
            st.pop();
        }
        st.push(num[i]);
       }
       while(k> 0){
        st.pop();
        k--;
       }
       string res;
       while(!st.empty()){
        res.push_back(st.top());
        st.pop();
       }
       int i = res.size() - 1;
       while(i>=0 and res[i]=='0'){
        res.pop_back();
        i--;
       }
       reverse(res.begin(), res.end());
       if(res.size()== 0){
        return "0";
       }
       return res;
    }
};