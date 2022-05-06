#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
/*
搜索二叉树的性质 :中序遍历之后得到的会是一个升序数组
利用弟归和非递归的方法.
prev存储之前一个节点的数字
*/


class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right),parent(parent) {}
};

class Solution
{
public:
    Solution();
    TreeNode* find_successor_node(TreeNode* x);
};

TreeNode* Solution::find_successor_node(TreeNode* x)
{
    if(x->right!=nullptr)
    {
        //找到右树的最左节点
        TreeNode *curr=x->right;
        while(curr->left)
        {
            curr=curr->left;
        }
    }

    else if(x->right!=nullptr)
    {
        //没有右树 一直往上找,直到父节点是当初节点的坐孩子
        TreeNode *curr,*parent;
        curr=x;
        parent=curr->parent;
        while(parent)
        {
            if(parent->left==curr)
            {
                return parent;
            }
            curr=parent;
            parent=parent->parent;
        }
    }
}
