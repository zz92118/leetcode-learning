/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
#include<vector>
using namespace std;
/*
prev = null
curr = head

最后return prev
*/

/*
输入一个节点 head，将「以 head 为起点」的链表反转，并返回反转之后的头结点。
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
    ListNode* reverseList(ListNode* head) {
        //递归翻转链表
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode *last = reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;

        return last;

    }
};
// @lc code=end
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    ListNode *curr,*prev;
    curr = new ListNode;
    prev = new ListNode;
    curr=head;
    prev=nullptr;
    while(curr!=nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
