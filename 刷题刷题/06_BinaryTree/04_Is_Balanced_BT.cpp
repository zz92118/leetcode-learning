#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

/*
介绍二叉树的递归套路
1）假设以X节点为头，假设可以向X左树和X右树要任何信息
2）在上一步的假设下，讨论以X为头节点的树，得到答案的可能性（最重要）
3）列出所有可能性后，确定到底需要向左树和右树要什么样的信息
4）把左树信息和右树信息求全集，就是任何一棵子树都需要返回的信息S
5）递归函数都返回S，每一棵子树都这么要求
6）写代码，在代码中考虑如何把左树的信息和右树信息整合出整棵树的信息
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
    //左右子树需要返回的信息
    class Info
    {
        public:
            bool is_balanced;
            int height;

            Info(bool i,int h)
            {
                is_balanced=i;  
                height=h;
            }
    };
    TreeNode *root;
    //处理过程
    Solution();
    Info* process(TreeNode *curr);
    //调用测试函数
    bool isBalanced(TreeNode* root)
    {
        return process(root)->is_balanced;//返回一个指针
    }
};

//::表示作用域
Solution::Info* Solution::process(TreeNode *curr)
{
    //1.向左树和右树要任何信息
    if(curr==nullptr)
    {
        return new Info(true,0);;
    }
    Info *left_info;
    Info *right_info;
    //左和右也通过弟归函数返回信息
    left_info = process(curr->left);
    right_info = process(curr->right);
    //处理当前节点的信息
    int height;
    bool balance=true;
    height = max(left_info->height,right_info->height) + 1;

    if(!left_info->is_balanced || !right_info->is_balanced || abs(left_info->height-right_info->height)>1)
    {
        balance = false ;
    }
    //递归返回当前节点的信息
    return new Info(balance,height);
}

Solution::Solution()
{
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    n1->left=n2;
    n1->right=n3;
    n3->left=n4;
    n3->right=n5;
    root=n1;
}

int main()
{
    Solution s;
    cout<<s.isBalanced(s.root);
}