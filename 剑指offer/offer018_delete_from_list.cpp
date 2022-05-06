#include<iostream>
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p,*pre;
        p=head;
        pre = p;
        if(val==head->val)
        {
            return head->next;
        }
        while( p && (p->val)!=val)
        {
            pre = p;
            p=p->next;
        }
        pre->next=p->next;
        return head;




    }
};