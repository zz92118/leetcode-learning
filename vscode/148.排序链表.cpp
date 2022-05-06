/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
merge sort 求出ListNode的中点
递归终止条件：list的长度为0或者1
主函数调用merge_sort(head,nullptr)
merge 的区间: [low,mid) [mid,high]
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
    ListNode* sortList(ListNode* head) {
        return merge_sort(head,nullptr);
    }

    ListNode* merge_sort(ListNode *head,ListNode *tail)
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        //!!!low , mid 这一段不使用尾结点
        if(head->next==tail)
        {
            head->next = nullptr;
            return head;
        }
        //快慢指针求出中点
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        while (fast != tail && fast->next!=tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow 为中间节点
        //归并过程 
        return merge(merge_sort(head,slow) , merge_sort(slow,tail));

    }
    ListNode* merge(ListNode *low,ListNode *high)
    {
        if(low==nullptr && high==nullptr)
        {
            return nullptr;
        }
        ListNode *p1,*p2;
        ListNode *head;
        ListNode *p3;
        head = new ListNode;
        p1=low;
        p2=high;
        p3=head;
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->val < p2->val)
            {
                ListNode *temp = new ListNode;
                temp -> val = p1->val;
                temp -> next = nullptr;

                p3->next=temp;
                p3=p3->next;
                p1=p1->next;
            }
            else 
            {
                ListNode *temp = new ListNode;
                temp -> val = p2->val;
                temp -> next = nullptr;

                p3->next=temp;
                p3=p3->next;
                p2=p2->next;
            }
        }

        if(p1!=nullptr)
        {
            p3->next = p1;
        }
        else if(p2!=nullptr)
        {
            p3->next = p2;
        }
        
        return head->next;
    }
};
// @lc code=end
ListNode* init()
{
    vector<int> arr;
    ListNode *head=new ListNode;
    ListNode *curr=head;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    
    int i;
    for(i=0;i<arr.size();i++)
    {
        if(i==0)
        {
            head->val = arr[i];
            head->next = nullptr;
        }
        else 
        {
            ListNode *temp = new ListNode;
            temp->val = arr[i];
            temp->next = nullptr;
            curr->next = temp;
            curr = curr->next;
        }

    }

    return head;
}

int main()
{
    ListNode *h=init();
    Solution s;
    s.sortList(h);
}


