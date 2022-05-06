#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {
public:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    MinStack() {

    }
    
    void push(int val) {
        data_stack.push(val);

        if(min_stack.empty())
        {
            min_stack.push(val);
        }
        else
        {
            min_stack.push(min(val,min_stack.top()));
        }

    }
    
    void pop() {
        min_stack.pop();
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */