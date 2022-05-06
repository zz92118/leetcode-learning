/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
using namespace std;
/*
设slow 和 fast相遇为 p
相遇节点和入换节点之间的距离为m
则 slow 走了 k，fast走了 2k
slow=head之后 继续走k-m
slow 和 fast相遇 return slow
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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
        {
            return nullptr;
        }

        ListNode *slow,*fast;

        slow=head;
        fast=head;

        while(fast!=nullptr && fast->next!=nullptr) // 空指针保护
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)//经过走之后 slow和fast相交
            {
                break;
            }
        }
        //无环
        if(fast==nullptr || fast->next==nullptr)
        {
            return nullptr;
        }
        
        slow = head;
        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};
// @lc code=end

