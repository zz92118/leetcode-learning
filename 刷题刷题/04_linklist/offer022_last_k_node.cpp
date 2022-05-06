#include<iostream>
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *head;
public:
    Solution();
    void out(ListNode* head);
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //少用一个slow指针省内存 多用一个slow
        ListNode *fast;
        int i=1;
        fast=head;
        while(i<k && fast!=nullptr)//先走k-1步
        {
            fast=fast->next;
            i++;
        }
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            head=head->next;
        }
        return head;
    }
    
};

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
    a.push_back(4);
    a.push_back(5);
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
        //curr记录最后一个非空节点 temp接在curr后面
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
    s.out(s.getKthFromEnd(s.head,2));
    return 0;
}