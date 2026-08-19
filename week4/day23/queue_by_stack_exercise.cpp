
#include <vector>
#include <string>
#include <stack>
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in_s.push(x);
    }
    
    int pop() {
        if(out_s.empty()){
            transfer();
        }
        int output=out_s.top();
        out_s.pop();
        return output;
    }
    
    int peek() {
        if(out_s.empty()){
            transfer();
        }
        int output=out_s.top();
        return output;
    }
    
    bool empty() {
        if(in_s.empty()&&out_s.empty()){
            return true;
        }
        return false;
    }
private:
    std::stack<int> in_s;
    std::stack<int> out_s;
    void transfer(){
        while(!in_s.empty()){
            int temp=in_s.top();
            out_s.push(temp);
            in_s.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */