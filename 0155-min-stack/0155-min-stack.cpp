class MinStack {
public:
stack<long long> st; 
long long min_value;
    MinStack() {
       min_value = LLONG_MAX;
    }
    
    void push(int value) {
       if(st.empty()){
         min_value = value;
         st.push(value);
       } 
       else{
        if(value>= min_value){
            st.push(value);
        }
        else{
            int temp = min_value;
            min_value = value;
            long long x = (long long)2* value - (long long)temp;
            st.push(x);
        }
       }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else{
            if(st.top()< min_value){
                long long temp = -st.top() + (long long)2* min_value;
                min_value = temp;
                st.pop();
            }
            else{
                st.pop();
            }
        }
    }
    
    int top() {
        if(st.empty()){
          return -1;
        }
        else{
            if(st.top()< min_value){
                return min_value;
            }
            else{
                return st.top();
            }
        }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        else{
            return min_value;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */