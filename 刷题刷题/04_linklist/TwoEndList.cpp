#include<iostream>
#include<vector>
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

class LinkList
{
public:
    Node *head;
public:
    LinkList();
    Node* TransverseList(Node *head);
    void out(Node* head);
    Node* delete_node(Node* head,int val);
};
Node* LinkList::delete_node(Node *head,int val)
{
    Node *curr,*prev;
    // 初始化
    curr=head;
    prev=nullptr;
    //先考虑头节点
    if(head->val==val)
    {
        head=head->next;
        head->last=nullptr;
        return head;
    }
    else
    {
        while(curr!=nullptr && curr->val!=val) 
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr->val==val)
        {

            Node *temp=curr->next;
            if(temp==nullptr)//删除的是最后一个节点
            {
                prev->next=nullptr;
                return head;
            }
            else
            {
                prev->next=temp;
                temp->last=prev;
                return head;
            }
        }
        else 
        {
            //不存在 
            cout<<"删除错误"<<endl;
            return nullptr;
        }
    }

}

Node* LinkList::TransverseList(Node *head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node *curr,*prev;
    prev=nullptr;
    curr=head;
    while(curr)
    {
        Node *temp;
        temp=curr->next;
        curr->next=prev;
        curr->last=temp;

        prev=curr;
        curr=temp;
    }
    return prev;
}

LinkList::LinkList()
{
    vector<int> a;
    int i;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    head=new Node;
    Node *curr;//curr为空 prev为链表最后一个节点
    head->last=nullptr;
    head->next=nullptr;
    //复杂度为o(n)
    //比单向的链表多了一个prev变量,用于处理新节点的last
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        if(i==a.begin())
        {
            head->val=*i;
            curr=head;
        }
        else
        {
            Node *temp;
            //1.新建节点
            temp = new Node;
            temp->next=nullptr;
            temp->val=*i;
            temp->last=curr;
            //2.接上
            curr->next=temp;
            //3.更新curr的prev
            curr=temp;
        }
    }
}

void LinkList::out(Node* head)
{
    Node *p;
    p=head;
    while(p!=nullptr)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    LinkList l;
    // Node *p=l.TransverseList(l.head);
    cout<<"TwoEnd"<<endl;
    // l.out(p);
    l.out(l.head);
    cout<<"delete"<<endl;;
    Node *p=l.delete_node(l.head,6);
    l.out(p);
    return 0;
}