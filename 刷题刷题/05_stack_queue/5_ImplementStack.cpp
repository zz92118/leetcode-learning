#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class MyStack {
public:
    queue<int> data;
    queue<int> help;
    MyStack() {

    }
    
    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        while(data.size()>1)
        {
            help.push(data.front());
            data.pop();
        }
        int x=data.front();
        data.pop();
        swap(data,help);//轮换回来
        return x;
    }
    
    int top() {
        while(data.size()>1)
        {
            help.push(data.front());
            data.pop();
        }
        int x=data.front();
        data.pop();
        help.push(x);
        swap(data,help);//轮换回来
        return x;
    }
    
    bool empty() {
        if(data.empty() && help.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */