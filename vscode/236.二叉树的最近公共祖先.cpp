/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
三种情况
情况 1，如果p和q都在以root为根的树中，函数返回的即使p和q的最近公共祖先节点。

情况 2，那如果p和q都不在以root为根的树中怎么办呢？函数理所当然地返回null呗。

情况 3，那如果p和q只有一个存在于root为根的树中呢？函数就会返回那个节点。

现根据二叉树框架写出来 然后写basecase 然后填充细节
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
        //根据三种情况得出的base case
        if(root==nullptr)
        {
            return nullptr;
        }

        if(root==p || root==q)
        {
            return root;
        }

        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode * right = lowestCommonAncestor(root->right,p,q);

        //后序需要返回的情况
        // 1.当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q ，返回 null 
        if(left==nullptr && right==nullptr)
        {
            return nullptr;
        }
        // 2.当 left 和 right 同时不为空 说明 p q 在以root为根节点的左右子树右侧 返回root为LCA （根据basecase看出来的）
        else if(left!=nullptr && right!=nullptr)
        {
            return root;
        }
        // 3. 当left和right只有一个为空，
        // p,q 其中一个在 root 的 右子树 中，此时 right 指向 pp（假设为 pp ）；
        // p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
        return left==nullptr? right : left;
    }
};
// @lc code=end

