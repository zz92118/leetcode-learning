#include<iostream>
#include<vector>
using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *head;
    Solution();
    void out(ListNode *head);
    ListNode* partition(ListNode* head, int x) {
        ListNode *current;
        ListNode *p;
        //初始化为空
        ListNode *less_head=nullptr,*less_tail=nullptr;
        ListNode *equal_head=nullptr,*equal_tail=nullptr;
        ListNode *larger_head=nullptr,*larger_tail=nullptr;
        current=head;
        while(current!=nullptr)
        {
            if(current->val<x)
            {
                if(less_head==nullptr)
                {
                    less_head = current;
                    less_tail = current;

                }
                else{
                    less_tail->next=current;
                    less_tail=current;

                }
            }

            else if(current->val==x)
            {
                if(equal_head==nullptr)
                {
                    equal_head = current;
                    equal_tail = current;
                    
                }
                else{
                    equal_tail->next=current;
                    equal_tail=current;

                }

            }

            else if(current->val>x)
            {
                if(larger_head==nullptr)
                {
                    larger_head = current;
                    larger_tail = current;

                }
                else{
                    larger_tail->next=current;
                    larger_tail=current;

                }
            }
            current=current->next;
        }
        //小于接等于
        if(less_tail!=nullptr)
        {
            less_tail->next=equal_head;
            if(equal_tail==nullptr)
            {
                equal_tail=less_tail;
            }
            else
            {
                equal_tail=equal_tail;
            }
        }
        //等于接大于
        if(equal_tail!=nullptr)
        {
            equal_tail->next=larger_head;
        }
        larger_tail->next=nullptr;
        return less_head != nullptr? less_head : (equal_head!=nullptr ? equal_head:larger_head);

    }
};

Solution::Solution()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(5);
    a.push_back(2);
    // a.push_back(1);
    head = new ListNode;
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


int main()
{
    Solution s;
    ListNode *res;
    res=s.partition(s.head,3);
    s.out(res);
}