/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
重点关注递归函数的作用，而不是跳进递归细节

1.把左侧展开
  把右侧展开

2.把左侧接上root
3.把右侧再接上左侧
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
    void flatten(TreeNode* root) {
        if(root==nullptr)
        {
            return ;
        }

        //1.把左右展开
        flatten(root->left);
        flatten(root->right);

        TreeNode *leftnode=root->left;
        TreeNode *rightnode=root->right;
        //2.接上左边
        root->left=nullptr;
        root->right=leftnode;
        //3.继续接上右边
        TreeNode *curr;
        curr=root;
        while(curr->right!=nullptr)
        {
            curr=curr->right;
        }
        curr->right=rightnode;
    }
};
// @lc code=end

