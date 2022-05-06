/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start

// Definition for a Node.
#include<iostream>
using namespace std;
/*
用两个函数
因为有时候两个需要相邻的节点有不同的父节点
因此模板中只提供了一个参数 提供的信息不够 因此自己再写一个函数
重点关注每个节点应该做什么，而不是跳进递归的套路里
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
        {
            return nullptr;
        }
        connecttwonode(root->left,root->right);
        return root;
    }

    void connecttwonode(Node *node1,Node *node2)
    {
        //最右侧的节点不用连接
        if(node1==nullptr || node2==nullptr)
        {
            return ;
        }

        node1->next=node2;
        connecttwonode(node1->left,node1->right);
        connecttwonode(node2->left,node2->right);
        connecttwonode(node1->right,node2->left);

    }
};
// @lc code=end

