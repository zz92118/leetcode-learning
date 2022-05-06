#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode *head;
public:
    Solution();
    void out(ListNode* head);
    bool isPalindrome(ListNode* head);
    bool isPalindrome2(ListNode* head);
    bool isPalindrome3(ListNode* head);
};

bool Solution::isPalindrome3(ListNode* head)
{
    //慢指针指向中点或者中点前一个
    //1 2 3 2 1
    //    *
    //1 2 3 3 2 1
    //    *  
    ListNode *slow,*fast;
    slow = head;
    fast = head;
    
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=nullptr;

    ListNode *prev;
    prev=slow;
    //后半部分转向
    while(fast!=nullptr)
    {
        ListNode *temp;
        temp = fast->next;
        fast->next=prev;
        prev=fast;
        fast=temp;
    }
    fast = prev;//尾节点
    slow = head;//头节点
    while(fast!=nullptr && slow!=nullptr)//fast和slow确保都不指到null的时候停止比较
    {
        if(fast->val != slow->val)
        {
            return false;
        }
        fast=fast->next;
        slow=slow->next;
    }
    //还原 利用prev节点 从尾到头
    fast=prev;
    prev=nullptr;
    while(fast!=nullptr)
    {
        ListNode *temp;
        temp=fast->next;
        fast->next=prev;
        prev=fast;
        fast=temp;
    }
    return true;

}

bool Solution::isPalindrome2(ListNode* head)
{
    //慢指针指向中点后一个或者中点后一个
    //1 2 3 2 1
    //      *
    //1 2 3 3 2 1
    //      *
    if(head==nullptr || head->next==nullptr)
    {
        return true;
    }
    ListNode *slow;
    ListNode *fast;
    ListNode *current;
    fast=head;//快指针
    slow=head->next;//慢指针
    stack<ListNode> s;
    while((fast->next)!=nullptr && (fast->next->next)!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=nullptr)
    {
        s.push(*slow);
        slow=slow->next;
    }
    current=head;
    while(!s.empty())
    {
        if((current->val)!=s.top().val)
        {
            return false;
        }
        s.pop();
        current=current->next;
    }
    //还原

    return true;
}

bool Solution::isPalindrome(ListNode* head)
{

    stack<ListNode> s;
    ListNode *current;
    current=head;
    while(current)
    {
        s.push(*current);
        current=current->next;
    }
    current=head;
    while(current)
    {
        if( (current->val)!=(s.top().val) )
        {
            return false;
        }
        s.pop();
        current=current->next;
    }
    return true;

}

void Solution::out(ListNode* head)
{
    ListNode *p;
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
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    head = new ListNode;
    ListNode *curr;
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        ListNode *p,*temp;
        p = new ListNode;
        temp = new ListNode;
        p=head;
        //heda 存储数据
        if(i==a.begin())
        {
            head->val=*i;
            head->next=nullptr;
            curr=head;
        }
        else
        {
            ListNode *temp;
            temp=new ListNode;
            temp->val=*i;
            temp->next=nullptr;
            curr->next=temp;
            curr=temp;
        }


    }
}

int main()
{
    Solution s;
    s.out(s.head);
    // cout<<s.isPalindrome(s.head)<<endl;
    // cout<<s.isPalindrome2(s.head)<<endl;
    cout<<s.isPalindrome3(s.head)<<endl;
    s.out(s.head);
    return 0;
}