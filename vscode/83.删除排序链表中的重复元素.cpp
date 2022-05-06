/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
同 26 的思想 快慢指针
slow 
fast
把slow和后面切断
最后 return head
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *slow,*fast;
        if(head==nullptr)
        {
            return nullptr;
        }
        slow = head;
        fast = head;

        while(fast!=nullptr)
        {
            if( fast->val != slow->val )
            {
                ListNode *temp = new ListNode;
                temp->val = fast->val;
                temp->next = nullptr;
                slow->next = temp ;

                slow = slow->next;//自增操作
            }
            fast = fast->next;
        }
        slow -> next = nullptr;
        return head ;
    }
};
// @lc code=end

int main()
{
    Solution s;

}

