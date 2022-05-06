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
#include<algorithm>
#include<queue>
using namespace std;
/*
树形dp 问题分解
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        //迭代实现
        //1.压入root 弹出并且打印
        //2.while循环 先右再左
        //bfs和前序遍历的唯一区别是stack和queue
        //有每一层的信息
        vector<vector<int> > result;
        queue<TreeNode*> q;
        TreeNode *curr;
        vector<int> a;

        if(root==nullptr)
        {
            return result;
        }
        q.push(root);
        while(!q.empty())
        {
            int level_size=q.size();//记录当前层的大小
            a.clear();
            // cout<<endl;
            while(level_size--)
            {
                curr=q.front();
                q.pop();
                a.push_back(curr->val);
                // cout<<curr->val<<" ";
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            result.push_back(a);
            // cout<<endl;
        }
        return result;
    }
};