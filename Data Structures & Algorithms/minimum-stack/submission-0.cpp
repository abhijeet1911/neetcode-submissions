class MinStack {
public:
stack<pair<int,int>>st;
int minval;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else {
            minval=min(st.top().second,val);
            st.push({val,minval});
        }
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
       return st.top().first;
        
    }
    
    int getMin() {
       return st.top().second;
    }
};
