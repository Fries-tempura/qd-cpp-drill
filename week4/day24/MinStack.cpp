#include <vector>
#include <string>
#include <stack>
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        now.push(value);
        if(min.empty()){
            min.push(value);
        }
        else{
            min.push(std::min(value,min.top()));
        }
    }
    
    void pop() {
        now.pop();
        min.pop();
    }
    
    int top() {
        return now.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    std::stack<int> now;
    std::stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */