/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
using namespace std;
/*

函数定义： 给出一个节点，一个q 一个p 返回他俩的LCA节点，具体可能有很多种情况

函数的参数 ：TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
root递归缩小问题的规模 要找的p q节点是不变的

如何处理返回值:
因为是BST 所以可以套用之前的BST框架

*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //base case
        if(root==nullptr)
        {
            return nullptr;
        }

        if( (root->val < p->val) && (root->val < q->val))
        {
            return lowestCommonAncestor(root->right,p,q);
        }

        else if((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
    }
};
// @lc code=end

