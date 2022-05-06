/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
重点关注递归函数的作用，而不是跳进递归细节

这个题一看就是要用递归
先找到最大值，然后递归的对左右进行划分
辅助函数build(nums,low,high) 对数组索引进行操作 
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = build(nums,0,nums.size()-1);
        return root;
    }
    //辅助函数 进行递归处理
    TreeNode* build(vector<int> nums,int low,int high)
    {
        //base case
        if(low>high)
        {
            return nullptr;
        }
        //找到划分点 index 和 value
        int i;
        int max_value=INT_MIN;
        int index=low;
        for(i=low;i<=high;i++)
        {
            if(nums[i]>=max_value)
            {
                max_value = nums[i];
                index = i;
            }
        }
        TreeNode *curr = new TreeNode(max_value);
        //递归的对左右进行划分
        curr->left = build(nums,low,index-1);
        curr->right = build(nums,index+1,high);
        
        return curr;
    }
};
// @lc code=end

