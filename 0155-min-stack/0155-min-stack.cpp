class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value > mini){
                st.push(value);
            }
            else{
                st.push(2LL * value - mini);
                // agar new minimum aata hai tab 2*value ko puraane mini se minus kiya jis baad mai 
                // top aur pop operation mai current mini nikaal le aur formula se previous mini mil jaai
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini){
            mini = 2LL * mini - x;
            // to get the previous mini back
        }
    }
    
    int top() {
        long long x = st.top();

        if(x < mini) return mini;
        else{
            return x;
        }
    }
    
    int getMin() {
        return mini;
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