/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
插入排序 
维护一个已经排好序的链表 最后一个是 *Tail表示排好序的链表的尾部节点
 if curr->val < tail->val 在head到tail的区域找到插入的节点 ，用prev指针表示插入节点的前一个节点
 else curr->val >= tail->val 在tail尾部插入

 每一步都要注意tail尾结点的next
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
    ListNode* insertionSortList(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode *dummy_head = new ListNode;

        dummy_head->next = head;

        ListNode *prev,*curr,*tail;
        curr = new ListNode;
        prev = new ListNode;
        curr = head->next;
        tail = head;//维护一个已经有序排列的链表，尾指针为tail

        //插入排序 curr移动一次，有序链表的长度+1
        while(curr!=nullptr)
        {
            prev = dummy_head;

            //找到curr需要插入的位置
            if(curr->val < tail->val)//在tail之前找到插入的位置
            {
                while(prev->next->val < curr->val)
                {
                    prev=prev->next;
                }
                //在prev后面插入curr
                //tail保持不变 更新tail的next指针
                tail->next=curr->next;
                curr->next=prev->next;
                prev->next=curr;
                //curr自增
            }

            else //在tail处更新curr
            {
                tail=tail->next;
            }
            curr=tail->next;

        }

        return dummy_head->next;

    }

};
// @lc code=end

ListNode* init()
{
    vector<int> arr;
    ListNode *head=new ListNode;
    ListNode *curr=head;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    
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
    s.insertionSortList(h);
    return 0;
}