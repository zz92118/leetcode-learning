/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
对链表进行遍历 A B节点
走完一遍之后 A接到headB B接到headA，返回第一个相遇的节点 

情况1：存在香蕉节点并返回
情况2：不存在香蕉节点 A==B时 a b 同时为nullptr
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA;
        ListNode *B=headB;

        while(A!=B)
        {
            A = A!=nullptr ? A->next : headB;
            B = B!=nullptr ? B->next : headA;
        }
        return A;

    }
};
// @lc code=end

int main()
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    // ListNode *c = new ListNode(3);
    // ListNode *d = new ListNode(4);

    // a->next = b;
    // c->next = d;
    cout<<(a->next==b->next);
}

