/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
#include<algorithm>
#include<queue>
using namespace std;
/*
二叉树的直径：
每一个节点左子树最大深度+右最大深度
在后续位置更新最大信息
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
    int maxdiameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth(root);
        return maxdiameter;
    }
    int max_depth(TreeNode *root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        else 
        {
            int leftdepth=max_depth(root->left);
            int rightdepth=max_depth(root->right);

            //后续位置处理diameter信息
            int mydiameter=leftdepth+rightdepth;
            maxdiameter=max(maxdiameter,mydiameter);

            int maxdepth = max(leftdepth,rightdepth)+1; 
            return maxdepth;         
        }
    }
};
// @lc code=end

