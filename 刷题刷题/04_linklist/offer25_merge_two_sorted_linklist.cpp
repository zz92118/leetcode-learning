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

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3,*p;
        l3 = new ListNode;
        p=l3;
        while(l1 && l2)
        {
            if((l1->val)<(l2->val))
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else 
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        if(l1)
        {
            p->next=l1;
        }
        else 
        {
            p->next=l2;
        }
        return l3->next;
    }
};