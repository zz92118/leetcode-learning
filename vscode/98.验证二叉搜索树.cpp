/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
using namespace std;
/*
1.中序遍历升序 
2.参数列表携带信息 递归的满足BST的当前节点>左边所有节点 
    bool isValid(TreeNode *root,TreeNode *min,TreeNode *max)
    将每一个根节点 root 作为左子树的最大值，同时作为右子树的最小值
3. 树形DP，从左右子树拿信息 

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
    bool isValidBST(TreeNode* root) {
        return isValid(root,nullptr,nullptr);
    }

    bool isValid(TreeNode *root,TreeNode *min,TreeNode *max)
    {
        //base case
        if(root==nullptr)
        {
            return true;
        }

        if(min!=nullptr && root->val<=min->val)
        {
            return false;
        }

        if(max!=nullptr && root->val>=max->val)
        {
            return false;
        }

        return isValid(root->left,min,root) && isValid(root->right,root,max);
    }   
};
// @lc code=end

