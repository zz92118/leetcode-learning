#include<stack>
#include<iostream>
using namespace std;

stack<int> s;


class ReversStackUseStack
{
public:
    int f(stack<int> &stack)
    {
        /*
            目的是返回栈底元素,栈的次序不变
        */
        int curr;
        curr=stack.top();
        stack.pop();
        //如果stack为空了,就通过递归栈向上返回

        if(stack.empty())
        {
            return curr;
        }

        else 
        {
            int last=f(stack);//从这里一直开辟新的递归栈一直到种终止件

            //沿递归栈返回的信息
            stack.push(curr);//之前记录的curr,返回现场 返回的时候越靠近栈底,越先入栈
            return last;//栈底元素向上返回
        }
    }

    void reverse(stack<int> &stack)
    {
        if(stack.empty())
        {
            //终止条件
            return ;
        }
        //将规模划分成n-1
        int i=f(stack);
        reverse(stack);
        //沿递归栈返回的信息
        stack.push(i);


    }
};


int main()
{
    s.push(3);
    s.push(2);
    s.push(1);
    ReversStackUseStack solution;
    solution.reverse(s);
    cout<<s.top()<<endl;
    return 0;
}