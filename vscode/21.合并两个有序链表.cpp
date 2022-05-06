/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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



struct ListNode {
int val;
ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr1 = new ListNode ;
        ListNode *curr2 = new ListNode ;
        ListNode *curr = new ListNode;
        ListNode *head = new ListNode;
        curr1 = list1 ;
        curr2 = list2 ;

        if(curr1 == nullptr && curr2 == nullptr)
        {
            return nullptr;
        }
        head = curr;
        while(curr1!=nullptr && curr2!=nullptr)
        {
            if( curr1->val < curr2->val)
            {
                curr->next = curr1;
                curr1 = curr1->next;
            }
            else 
            {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        if(curr1)
        {
            curr->next = curr1;
        }
        else 
        {
            curr->next = curr2;
        }

        return head->next;

    }
};
// @lc code=end

