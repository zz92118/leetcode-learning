/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
#include<math.h>
using namespace std;
/*
将算法的复杂度，通过完全二叉树 从 n 优化到 logn*logn
完全二叉树一定有一颗子树会是满二叉树,从而优化时间复杂度
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
    int countNodes(TreeNode* root) {
        TreeNode *leftnode=root;
        TreeNode *rightnode=root;
        int left_hight=0;
        int right_hight=0;

        while(leftnode!=nullptr)
        {
            leftnode=leftnode->left;
            left_hight++;
        }

        while(rightnode!=nullptr)
        {
            rightnode=rightnode->right;
            right_hight++;
        }

        if(right_hight==left_hight)
        {
            return pow(2,right_hight)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// @lc code=end


// 普通二叉树节点个数
// public int countNodes(TreeNode root) {
//     if (root == null) return 0;
//     return 1 + countNodes(root.left) + countNodes(root.right);
// }

// 满二叉树节点个数
// public int countNodes(TreeNode root) {
//     int h = 0;
//     // 计算树的高度
//     while (root != null) {
//         root = root.left;
//         h++;
//     }
//     // 节点总数就是 2^h - 1
//     return (int)Math.pow(2, h) - 1;
// }


