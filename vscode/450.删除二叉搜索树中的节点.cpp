/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

函数定义： 给出一个节点，一个要删除的节点的值，删除该节点，并返回删除后的该节点

情况 1 删除节点左右子树都是null,则直接删除root节点 
情况 2 左右子树有一个是null，就直接把非空的接上
情况 3 左右子树都为非空 ， 找到左子树的最大节点 或者右子树的最小节点

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case 进行删除操作
        if(root==nullptr)
        {
            return nullptr;
        }
        if(root->val==key)
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                return nullptr;
            }
            else if(root->left!=nullptr && root->right!=nullptr)
            {
                TreeNode *curr = getmin(root->right);
                //找到了最小节点
                //通过当前节点构建右子树!!!!!
                //左子树不管，递归构建右子树
                root->right=deleteNode(root->right,curr->val);
                
                curr->left=root->left;
                curr->right=root->right;
                return curr;
            }
            else 
            {
                if(root->left==nullptr)
                {
                    return root->right;
                }
                else if(root->right==nullptr)
                {
                    return root->left;
                }
            }
        }

        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }

        return root;
    }
    TreeNode* getmin(TreeNode* root)
    {
        TreeNode *curr=root;
        while(curr->left!=nullptr)
        {
            curr=curr->left;
        }
        return curr;
    }
};
// @lc code=end

