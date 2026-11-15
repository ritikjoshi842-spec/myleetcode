class Solution {
public:
vector<int> fx(vector<int>& heights){
    vector<int> res;
    stack<int> st;
    int n = heights.size();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() and heights[i]<= heights[st.top()]){
            st.pop();
        }
        if(st.empty()){
            res.push_back(n);
        }
        else{
            res.push_back(st.top());
        }
        st.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}
vector<int> gx(vector<int> &heights){
    vector<int> res;
    stack<int> st;
    int n = heights.size();
    for(int i = 0; i < n; i++){
        while(!st.empty() and heights[i]<= heights[st.top()]){
            st.pop();
        }
        if(st.empty()){
            res.push_back(-1);
        }
        else{
            res.push_back(st.top());
        }
        st.push(i);
    }
    return res;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = gx(heights);
        vector<int> right = fx(heights);
        int max_element = 0;
        for(int i = 0; i< n; i++){
           max_element = max(max_element, (right[i] - left[i] - 1)* heights[i]); 
        }
        return max_element;
    }
};