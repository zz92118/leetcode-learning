#include<iostream>
#include<stack>
using namespace std;


class MyQueue {
public:
    stack<int> push_stack;
    stack<int> pop_stack;
    MyQueue() {

    }
    
    void push(int x) {
        push_stack.push(x);
    }
    
    int pop() {
        while(!push_stack.empty())
        {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        int x=pop_stack.top();
        pop_stack.pop();
        while(!pop_stack.empty())
        {
            push_stack.push(pop_stack.top());
            pop_stack.pop();
        }
        return x;
    }
    
    int peek() {
        while(!push_stack.empty())
        {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        int x=pop_stack.top();

        //少了一个pop
        while(!pop_stack.empty())
        {
            push_stack.push(pop_stack.top());
            pop_stack.pop();
        }    
        return x;   
    }
    
    bool empty() {
        return push_stack.empty();
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