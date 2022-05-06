/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
1.找到postorder和inorder的根节点
2.递归的构建左右子树
3.确定需要的变量 posStart posEnd Root inStart inEnd index
4. 辅助函数build的函数原型

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder,int posStart,int posEnd)
    {
        //base case
        if(inStart>inEnd || posStart>posEnd)
        {
            return nullptr;
        }

        int rootVal = postorder[posEnd];
        int index = 0;
        for(index=inStart;index<=inEnd;index++)
        {
            if(inorder[index]==rootVal)
            {
                break;
            }
        }

        int leftsize=index-inStart;

        TreeNode *curr = new TreeNode(rootVal);

        curr->left=build(inorder,inStart,index-1,postorder,posStart,posStart+leftsize-1);
        curr->right=build(inorder,index+1,inEnd,postorder,posStart+leftsize,posEnd-1);

        return curr;
    }
};
// @lc code=end

