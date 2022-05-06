/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
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
#include<iostream>
using namespace std;
/*
ListNode* reverse(ListNode* head,ListNode* tail): 
    反转从head 到 tail的链表 
    即将原来以nullptr为尾部的链表转化为tail
    反转的区间是[head,tail)
ListNode* reverseKGroup(ListNode* head, int k) 
    理解成一个黑盒
    head为头结点 长度为k进行反转

    结束之后反转接下来的k个节点

    1.确定k的长度
    2.反转链表 区间[head,tail) ，返回newhead
    3.递归调用 head-》next = reverse(curr,k) head保持不变 
    4.return newhead;

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i,j=0;

        // base case 
        // k个一组
        ListNode *curr=head;
        for(i=0;i<k;i++)
        {
            //不满足k个直接return
            if(curr==nullptr)
            {
                return head;
            }
            curr=curr->next;
        }

        ListNode *newhead = reverse(head,curr);//反转后的节点

        head->next = reverseKGroup(curr,k);

        return newhead;//返回的是反转过后的节点



    }

    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode *curr,*prev;
        curr = head;
        prev = nullptr;

        while(curr!=tail)
        {
            ListNode *temp = new ListNode;
            temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }
};
// @lc code=end

