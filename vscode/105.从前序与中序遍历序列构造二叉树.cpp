/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
1.preorder的根节点rootVal
  inorder的根节点 遍历inorder数组
2.递归的构建左右子树
3.确定需要的变量 rootVal preStart preEnd  inStart inEnd index
4. 辅助函数build的函数原型
左右子树的起始终止位置要确定 前序不要出现index 
前序的信息只要和prestart preend leftsize有关
中序的信息 instart inend index 

最后return
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int> inorder,int inStart,int inEnd)
    {
        if(preStart>preEnd || inStart>inEnd)
        {
            return nullptr;
        }
        //找到inorder的root节点 在inorder里面找
        int rootVal = preorder[preStart];
        int index;
        for(index=inStart;index<=inEnd;index++)
        {
            if(inorder[index]==rootVal)
            {
                break;
            }
        }
        //i位置是inorder的root
        int leftsize = index - inStart;
        //构造根节点
        TreeNode *curr = new TreeNode(rootVal);
        curr->left=build(preorder,preStart+1,preStart+leftsize,inorder,inStart,index-1);
        curr->right=build(preorder,preStart+leftsize+1,preEnd,inorder,index+1,inEnd);

        return curr;
    }
};
// @lc code=end

