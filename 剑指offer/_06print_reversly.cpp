#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
 * Definition for singly-linked list.
 */

struct ListNode {
// public:
    int val;
    ListNode *next;
    //   ListNode(int x) : val(x), next(NULL) {}
};


  
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> v;

        while (head!=NULL)
        {
            s.push(head->val);
            head=head->next;
        }

        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }

    vector<int> reversePrintrecursive(ListNode* head, vector<int> &res)
    {
        if(head->next!=NULL)
        {
            reversePrintrecursive(head->next,res);
            res.push_back(head->val);
        }
    }
};

void inslist(struct ListNode *h,int x){
    struct ListNode *L = h;
	struct ListNode *p = NULL;
	while (L->next != NULL)
	{
		L = L->next;//遍历找到尾节点 
	}
    //头指针h之后不断指向新的值 从而改变了 h-next为NULL
	p = new struct ListNode;//开辟新的节点 
 	p->val = x;//赋值 
	p->next = NULL;//设置为尾节点 
	L->next = p;//挂在原来尾节点之后 
}

int main()
{
    ListNode *head,*p,*q;
    int i;
    int x;
    for(i=0;i<5;i++)
    {
        cin>>x;
        p->val=x;
        p->next=NULL;
        q->next=p;
    }

}