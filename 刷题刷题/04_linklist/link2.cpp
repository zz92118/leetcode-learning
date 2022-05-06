#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *last;
};

class LinkList2
{
public:
    ListNode *head; //head不存储数据
    ListNode *tail; //linklist的尾部存储数据

public:
    LinkList2();//构造方法
    void out(ListNode *h);
    ListNode *getelement(ListNode *h,int index);
    void insertelement(ListNode *h,int index,int x);
    void deleteelement(ListNode *h,int index); 
    void reverse(ListNode *h);
};

void LinkList2::reverse(ListNode *h)
{
    ListNode *temp;
    ListNode *current=h->next;
    while(current!=nullptr)
    {
        temp=current->last;
        current->last=current->next;
        current->next=temp;
        current=current->last;
    }
}


void LinkList2::deleteelement(ListNode *h,int index)
{
    int i;
    i=1;
    ListNode *p;
    ListNode *q;//指向前一个节点
    ListNode *temp;
    q=h;
    p=h->next;
    while(p!=nullptr && i<index)
    {
        q=p;
        p=p->next;
        i++;
    }
    if(i==index && p->next)
    {
        q->next=p->next;
        (p->next)->last=q;
        return;
    }
    if(p->next==nullptr)
    {
        q->next=p->next;
        tail=q;
    }

}


void LinkList2::insertelement(ListNode *h,int index,int x)
{
    int i;
    i=1;
    ListNode *p;
    ListNode *q;//指向前一个节点
    ListNode *temp;
    q=h;
    p=h->next;
    while(p!=nullptr && i<index)
    {
        q=p;
        p=p->next;
        i++;
    }
    if(i==index)
    {
        temp = new ListNode;
        temp->val=x;
        temp->next=p;
        temp->last=q;
        q->next=temp;
    }

    else if(p==nullptr)//插入的节点作为尾节点
    {
        temp->val=x;
        temp->next=nullptr;
        temp->last=q;
        q->next=temp;
        tail=temp;//
    }


}

ListNode* LinkList2::getelement(ListNode *h,int index)
{
    int i=1;//第i个
    ListNode *p;
    p=h->next;
    while(p!=nullptr && i<index)
    {
        p=p->next;
        i++;
    }
    if(i==index)
    {
        cout<<p->val;
    }
    if(p==nullptr)
    {
        cout<<"error";
        // return ;
    }
    return p;
    
}

LinkList2::LinkList2()
{
    int n;
    int i;
    int x;
    head = new ListNode;
    tail = new ListNode;
    head->next = nullptr;
    head->last = nullptr;
    tail = head;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        ListNode *t;
        t = new ListNode;
        //构造新来的节点
        t->val=x;
        t->next=nullptr;
        t->last=tail;
        //接到原来的链表之后
        tail->next=t;
        //更新尾节点
        tail=t;

        //insert
    }
}

void LinkList2::out(ListNode *h)
{
    ListNode *p;
    p=h->next;//跳过头节点
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}


int main()
{
    LinkList2 s;
    // s.out(s.head);
    // s.getelement(s.head,4);
    s.deleteelement(s.head,4);
    s.out(s.head);
    cout<<s.tail->val;
    return 0;
}