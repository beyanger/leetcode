class MinStack {
public:
    stack<int> stk;
    stack<int> min;

    void push(int x) {
        stk.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }

    void pop() {
        if(stk.top() == min.top())
            min.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
