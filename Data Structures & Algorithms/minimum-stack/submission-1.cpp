class MinStack {
public:
    stack<int> s;
    stack<int> minS;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if (minS.empty()) {
            minS.push(val);
        } else {
            minS.push(min(minS.top(), val));
        }
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        if (!s.empty()) return s.top();
        return -1;
    }
    
    int getMin() {
        if (!minS.empty()) return minS.top();
        return -1;
    }
};
