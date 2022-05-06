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
    vector<int> preorderTraversal(TreeNode* root);
    vector<int> preorderTraversal2(TreeNode* root);//非递归实现
    //中序遍历
    vector<int> midorderTraversal(TreeNode* root);//非递归


    //后序
    vector<int> postorderTraversal1(TreeNode* root);//非递归实现
    vector<int> postrderTraversal2(TreeNode* root);//非递归实现

    //宽度优先遍历 queue
    vector<int> bfsTraversal(TreeNode* root);
    vector<int> bfsTraversal2(TreeNode* root);
    vector<int> bfsTraversal3(TreeNode* root);

};

vector<int> Solution::bfsTraversal3(TreeNode* root)//非递归 让空节点也加入 用于序列化 反序列化
{

    queue<TreeNode*> q;
    TreeNode *curr;
    vector<int> a;

    curr=root;
    q.push(curr);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr)//这里判空
        {
            // cout<<curr->val<<" ";
            a.push_back(curr->val);
            q.push(curr->left);//
            q.push(curr->right);//这里不判空
        }
    }

    while(!q.empty())
    {
        curr=q.front();
        q.pop();

        if(curr==nullptr)
        {
            continue;
        }

        else 
        {
            a.push_back(curr->val);

        }
        q.push(curr->left);
        q.push(curr->right);
    }
    return a;
}


vector<int> Solution::bfsTraversal2(TreeNode* root)//非递归 可以每层加一次循环
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
        return a;
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
    return a;

}

vector<int> Solution::bfsTraversal(TreeNode* root)
{
    //迭代实现
    //1.压入root 弹出并且打印
    //2.while循环 先右再左
    //bfs和前序遍历的唯一区别是stack和queue

    vector<int> a;
    queue<TreeNode*> q;
    TreeNode *curr;
    if(root==nullptr)
    {
        return a;
    }
    q.push(root);
    while(!q.empty())
    {
        curr=q.front();
        a.push_back(curr->val);
        cout<<curr->val<<" ";
        q.pop();
        //左右子树 一起进去
        if(curr->left)
        {
            q.push(curr->left);
        }
        if(curr->right)
        {
            q.push(curr->right);
        }
    }
    return a;


}
vector<int> Solution::midorderTraversal(TreeNode* root)
{
    vector<int> a;
    stack<TreeNode*> s;
    TreeNode *curr;
    curr=root;
    if(!root)
    {
        return a;
    }
    //不知道为啥报错了??? leetcode上刷出来了
    while( !s.empty() || curr!=nullptr)
    {
        if(curr)
        {
            s.push(curr);
            curr=curr->left;
        }
        else 
        {
            curr=s.top();
            s.pop();
            a.push_back(curr->val);
            cout<<curr->val<<" ";
            curr=curr->right;
        }
    }
}


void Solution::preorder(TreeNode* root)
{
    if(root)
    {
        a.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


vector<int> Solution::preorderTraversal2(TreeNode* root)
{
    //迭代实现
    //1.压入root 弹出并且打印
    //2.while循环 压入弹出节点的右左子树 先右再左
    //bfs和前序遍历的唯一区别是stack和queue
    vector<int> a;
    stack<TreeNode*> s;
    TreeNode *curr;
    if(root==nullptr)
    {
        return a;
    }
    //1.压入root 弹出并且打印
    s.push(root);
    //每次弹出的时候压入弹出节点的左右子树
    while(!s.empty())
    {
        curr=s.top();
        a.push_back(curr->val);
        s.pop();
        if(curr->right)
        {
            s.push(curr->right);
        }
        if(curr->left)
        {
            s.push(curr->left);
        }
    }
    return a;
    


}


vector<int> Solution::preorderTraversal(TreeNode* root)
{
    preorder(root);
    return a;
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
    s.bfsTraversal3(s.root);
}