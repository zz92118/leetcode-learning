#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(){};
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node *head;
public:
    Solution();
    Node* copyRandomList(Node* head);
    Node* copyRandomList2(Node* head);

    void out(Node *head);
};

Node* Solution::copyRandomList2(Node* head)
{
    //1.不考虑random 1-1'-2-2'-3-3';
    //2.使用next设置1',2‘,3’的random指针 考虑random的null
    //3.在next方向上分离链表 考虑curr的null
    //temp变量暂存curr的下一个原本的节点
    Node *curr;
    Node *temp;
    Node *copy;
    Node *head_copy;
    curr=head;
    //1.不考虑random 1-1'-2-2'-3-3'; curr:当前 temp:暂存下一届点 copy:copy的random节点,new出来
    while(curr)
    {
        temp = curr->next; //copy的next
        copy = new Node(curr->val);//new 的 node指针没有被初始化
        curr->next=copy;
        copy->next=temp;
        curr=temp;//更新curr
    }
    //2.使用next设置1',2‘,3’的指针
    curr=head;
    while(curr)
    {
        temp=curr->next->next;//暂处 1--2
        copy=curr->next;//1‘
        if(curr->random==nullptr)//空指针保护
        {
            copy->random=nullptr;
        }
        else 
        {
            copy->random=(curr->random->next);
        }
        curr=temp;//更新curr
    }
    curr=head;
    if(head==nullptr)
    {
        return nullptr;
    }
    //3.在next方向上分离链表 考虑curr的null 确保原来的链表不变
    head_copy=head->next;
    while(curr!=nullptr)
    {
        copy=curr->next;
        temp=curr->next->next;
        curr->next=temp;//原链表
        if(temp!=nullptr)
        {
            copy->next=temp->next;//新链表
        }
        else{
            copy->next=nullptr;
        }
        curr=temp;
    }
    //head_copy是复制的节点
    //heda是与哪来的节点 两者一样
    return head_copy;

}

Node* Solution::copyRandomList(Node* head)
{
    //
    // Node1---------Node1_
    // Node2---------Node2_
    // Node3---------Node3_

    unordered_map<Node*, Node*> cachedNode;
    Node *curr;
    curr=head;
    while(curr!=nullptr)
    {
        Node* cachenode = new Node(curr->val);//new 的 node指针没有被初始化
        cachedNode[curr]=cachenode;// key->value映射
        curr=curr->next;
        
    }
    curr=head;
    while (curr!=nullptr)
    {
        // 新节点的next = 原节点的next的克隆节点
        cachedNode[curr]->next = cachedNode[curr->next];
        cachedNode[curr]->random = cachedNode[curr->random];
        curr=curr->next;
    }
    return cachedNode[head];
    
}


void Solution::out(Node* head)
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

Solution::Solution()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    // a.push_back(1);
    head = new Node;
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        Node *p,*temp;
        p = new Node;
        temp = new Node;
        p=head;
        //heda 存储数据
        if(i==a.begin())
        {
            head->val=*i;
            head->next=nullptr;
        }
        else
        {
            while(p->next!=nullptr)
            {
                p=p->next;//p打到末尾
            }
            //把temp接到p之后
            temp->val=*i;
            temp->next=nullptr;
            p->next=temp;
        }


    }
}

int main()
{

}