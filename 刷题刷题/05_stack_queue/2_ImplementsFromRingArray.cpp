#include<iostream>
using namespace std;
#define N 10;

class mystack
{
public:
    int a[10];
    int index;//
    int size;
public:
    mystack();
    void push(int x);//覆盖
    void pop();//不覆盖
    int gettop();
    bool isempty();
    bool isfull();
};

class myqueue
{
public:
    int a[10];
    int size;
    int current_size;
    int push_index;
    int pop_index;

    myqueue();
    void push(int x);//覆盖
    void pop();//不覆盖
    int gettop();
    bool isempty();
    bool isfull();
    int nextindex(int x);//!!!!!环形数组求下一个
};

int myqueue::nextindex(int x)
{
    return x+1<size ? x+1:0;
}

myqueue::myqueue()
{
    size=N;
    current_size=0;
    push_index=0;
    pop_index=0;
}

bool myqueue::isfull()
{
    return size==current_size;
}

bool myqueue::isempty()
{
    return current_size==0;
}



int myqueue::gettop()
{
    return a[pop_index];
}

void myqueue::push(int x)
{
    if(current_size>=size)
    {
        throw ;
    }
    else 
    {
        a[push_index]=x;
        push_index=nextindex(push_index);
        size++;
    }
}

void myqueue::pop()
{
    if(isempty())
    {
        throw;
    }
    else 
    {
        pop_index=nextindex(pop_index);
        size--;
    }
}


mystack::mystack()
{
    size=N;
    index=-1;
}

void mystack::push(int x)
{
    index++;
    a[index]=x;
} 
void mystack::pop()
{
    cout<<a[index]<<endl;
    index--;
} 

int mystack::gettop()
{
    return a[index];
} 

bool mystack::isempty()
{
    return (index<0);
}
bool mystack::isfull()
{
    return (index>=size);
}



int main()
{
    mystack s;
    cout<<s.isempty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isempty()<<endl;
    return 0;
}