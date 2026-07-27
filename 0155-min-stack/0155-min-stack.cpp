class MinStack {
public:
    stack<int> st1;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(st1.empty() || st1.top() >= value){
            st1.push(value);
        }
    }
    
    void pop() {
        if(st1.top() == st.top()) st1.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st1.top();
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