#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
非递归实现的总体思路: 使用一个stack 用curr指针遍历,并且弹出
bfs和前序遍历的唯一区别是stack和queue

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
class Solution {
public:
    vector<int> a;
    TreeNode *root;
    Solution();
    //前序遍历
    void preorder(TreeNode* root);

    vector<vector<int> > levelOrder(TreeNode* root);



}; 

vector<vector<int> > levelOrder(TreeNode* root)//非递归 可以每层加一次循环
{
    //迭代实现
    //1.压入root 弹出并且打印
    //2.while循环 先右再左
    //bfs和前序遍历的唯一区别是stack和queue
    //有每一层的信息
    vector<int> a;
    queue<TreeNode*> q;
    TreeNode *curr;
    if(root==nullptr)
    {
        // return a;
    }
    q.push(root);
    while(!q.empty())
    {
        int level_size=q.size();//记录当前层的大小

        // cout<<endl;
        while(level_size--)
        {
            curr=q.front();
            q.pop();
            a.push_back(curr->val);
            cout<<curr->val<<" ";
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        // cout<<endl;
    }
    // return a;

}







Solution::Solution()
{
    TreeNode *n1= new TreeNode(1);
    TreeNode *n2= new TreeNode(2);
    TreeNode *n3= new TreeNode(3);
    TreeNode *n4= new TreeNode(4);
    TreeNode *n5= new TreeNode(5);
    TreeNode *n6= new TreeNode(6);
    TreeNode *n7= new TreeNode(7);
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    root=n1;
}

int main()
{
    Solution s;
    s.levelOrder(s.root);
}