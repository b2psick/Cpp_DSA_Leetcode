class MinStack {
public:
    // stack<int> st1;
    // stack<int> st;

    //another solution by using one stack of pair in which we calculate min as we push everytime also we can do this using linkelist too
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        // st.push(value);
        // if(st1.empty() || st1.top() >= value){
        //     st1.push(value);
        // }
        if(st.empty()){
            st.push({value,value});
        }else st.push({value,min(value,st.top().second)});
    }
    
    void pop() {
        // if(st1.top() == st.top()) st1.pop();
        // st.pop();
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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