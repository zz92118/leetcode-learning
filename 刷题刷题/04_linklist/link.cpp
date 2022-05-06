#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode2 {
    int val;
    ListNode2 *next;
    ListNode2 *last;
    // ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode *head;
    ListNode *t;

public:
    Solution();//初始化方法
    void out(ListNode *h);
    ListNode* reverseList(ListNode* head);
};

ListNode* Solution::reverseList(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur)
    {
        ListNode* temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    //cur == nullptr
    return pre;
}


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
    s.t=s.reverseList(s.head);
    s.out(s.t);
    return 0;

}