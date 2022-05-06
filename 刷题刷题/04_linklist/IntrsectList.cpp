#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

/*
两种方法
哈希表
快慢指针
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //哈希set实现 查找另一个链表有没有节点相同
        unordered_set<ListNode*> s;
        ListNode *curr;
        curr=headA;
        while(curr)
        {
            s.insert(curr);
            curr=curr->next;
        }
        curr=headB;
        while(curr)
        {
            if(s.count(curr))
            {
                return curr;
            }
            curr=curr->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode *currA=headA;
        ListNode *currB=headB;
        //currA:走过(a-c)+c +b -c=a+b-c
        //currA:走过(b-c)+c +a -c=b+a-c
        if(headA==nullptr || headB==nullptr)
        {
            return nullptr;
        }

        while( currA!=currB)
        {
            if(currA==nullptr)
            {
                currA->next=headB;
            }
            if(currB==nullptr)
            {
                currB->next=headA;
            }
            currA=currA->next;
            currB=currB->next;
        }
        return currA;
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
}