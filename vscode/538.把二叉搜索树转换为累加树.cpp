/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<iostream>
#include<vector>
using namespace std;
/*
中序遍历改一下 BST改成降序序列

在每个节点上加上累加和 用变量sum记录

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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        inorder_sum(root);
        return root;
    }

    void inorder_sum(TreeNode *root)
    {
        if(root==nullptr)
        {
            return ;
        }
        inorder_sum(root->right);
        //中序处理
        sum+=root->val;
        root->val=sum;
        inorder_sum(root->left);
    }
};
// @lc code=end

