class MinStack {
private:
    stack<int> s;
    stack<int> ms;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ms.empty() || val <= ms.top()){
            ms.push(val);
        }
    }
    
    void pop() {
        if(!ms.empty() && s.top() == ms.top()){
            ms.pop();
        }
        s.pop();
        
    }
    
    int top() {
        return s.top(); 
    }
    
    int getMin() {
        return ms.top();
    }
};
