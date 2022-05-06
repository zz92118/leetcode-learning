/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
快指针先走n步
不用prev指针 利用fast->next!=nullptr 的空指针保护 ，
、最后fast指向链表最后一个节点
、slow指向删除节点的前一个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
        ListNode *slow,*fast;
        slow = head ;
        fast = head ;
        if(head->next==nullptr)
        {
            return nullptr;
        }
        //快指针先走
        for(i=0;i<n;i++)
        {
            fast=fast->next;
        }
        //倒数N 就是第一个节点
        if(fast==nullptr)
        {
            return head->next;
        }
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;

        return head;
    }
};
// @lc code=end

