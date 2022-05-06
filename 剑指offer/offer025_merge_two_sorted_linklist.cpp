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
        ListNode *p1,*p2,*p3;
        p1=l1;
        p2=l2;
        p3 = new ListNode;
        while(p1 && p2)
        {
            if((p1->val)<(p2->val))
            {
                p3->val=p1->val;
                p1=p1->next;
            }
            else 
            {
                p3->val=p2->val;
                p2=p2->next;
            }
        }

    }
};