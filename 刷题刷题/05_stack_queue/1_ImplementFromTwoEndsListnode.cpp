#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *last;
public:
    Node(){};
    Node(int x)
    {
        val=x;
    }
};

class myqueue
{
public:
    Node *head,*tail;
public:
    void push(int x);//头部进入
    void pop();//尾部出
    int gettop();
    bool isempty();
    myqueue();
};

bool myqueue::isempty()
{
    return head==nullptr ? 1:0;
}
myqueue::myqueue()
{
    head = nullptr;
    tail = nullptr;
}

int myqueue::gettop()
{
    return tail->val;

}
void myqueue::pop()
{
    //尾部
    Node *temp;
    temp=new Node;
    if(head==tail)
    {
        cout<<tail->val<<endl;
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        cout<<tail->val<<endl;
        temp=tail->last;
        temp->next=nullptr;
        tail=temp;
    }

}
void myqueue::push(int x)
{
    Node *curr;
    curr=new Node;

    if(head==nullptr)
    {
        head=new Node;
        head->val=x;
        head->last=nullptr;
        head->next=nullptr;
        tail=head;
    }
    //在头部插入 注意head指针
    else
    {
        curr->val=x;
        curr->last=nullptr;
        curr->next=head;
        head->last=curr;
        head=curr;
    }
}

int main()
{
    myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(100);
    cout<<q.isempty()<<endl;
    q.pop();
    cout<<q.isempty()<<endl;

    return 0;
}