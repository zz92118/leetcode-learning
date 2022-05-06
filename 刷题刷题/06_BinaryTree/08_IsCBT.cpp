#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
/*
完全二叉树的性质:
层次遍历去找第一个为空的节点
对bfs遍历稍作修改
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *curr;
        bool leaf_flag=false;
        if(root==nullptr)
        {
            return true;
        }
        curr=root;
        q.push(curr);
        while(!q.empty())
        {
            curr=q.front();
            q.pop();
            if(curr==nullptr)
            {
                leaf_flag=1;
                continue;
            }
            //激活了leaf flag之后一定要每一个节点都是空
            if(leaf_flag)//已经激活,并且curr!=null的时候才会进入这个分枝
            {
                return false;
            }

            q.push(curr->left);
            q.push(curr->right);
        }
        return true;
    }
};