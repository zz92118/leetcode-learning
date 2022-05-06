#include<iostream>
#include<unordered_set>
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
    // ListNode(int x) : val(x),next(NULL){}
    
};

class Solution {
public:
    ListNode *head;

    void out(ListNode *head);
    Solution();

    bool hasCycle(ListNode *head) {
        ListNode *current;
        unordered_set<ListNode*> s;
        current=head;
        while (current)
        {
            if(s.count(current))
            {
                return true;
            }

            else 
            {
                s.insert(current);
            }
            current=current->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {
        ListNode *slow,*fast;
        if(head==nullptr || head->next==nullptr)
        {
            return false;
        }
        //slow一次走一步
        //fast一次走两步
        slow=head;
        fast=head->next;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        // 走到底都没有相交　
        return false;
    }
};

void Solution::out(ListNode *h)
{
    ListNode *p;
    p=h;
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

Solution::Solution()
{
    int n;
    int i=0;
    int x;
    cin>>n;
    head = new struct ListNode;
    ListNode *curr;
    head->next=NULL;//head不存储数据
    for(i=0;i<n;i++)
    {
        cin>>x;
        {
            if(i==0)
            {
                head->val=x;
                head->next=nullptr;
                curr=head;
            }
            else 
            {
                //1.新建
                ListNode *temp;
                temp=new ListNode;
                temp->val=x;
                temp->next=nullptr;
                //2.接上
                curr->next=temp;
                //3.更新
                curr=temp;
            }
        }
    }


}

int main()
{
    Solution s;
    s.out(s.head);
    cout<<s.hasCycle(s.head)<<endl;
    return 0;
}