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
    class Info{
    public : 
        int max_distance;
        int height;
        Info(int x,int h)
        {
            max_distance = x;
            height = h;
        }
    };
    TreeNode *root;
    Solution();
    int MaxDistance(TreeNode *head)
    {
        return process(head)->max_distance;
    }
    Info* process(TreeNode *curr);

};

//::表示作用域
Solution::Info* Solution::process(TreeNode *curr)
{
    if(curr==nullptr)
    {
        return new Info(0,0);
    }

    Info *left_info=process(curr->left);
    Info *right_info=process(curr->right);

    int curr_height;
    int curr_max_distance;
    curr_height = max(left_info->height,right_info->height)+1;
    //1.与当前节点无关, 最大距离为左右最大值
    //2.与当前节点有关,最大距离为左高+又高+1
    curr_max_distance = max (max(left_info->max_distance,left_info->max_distance),left_info->height+right_info->height);
    return new Info(curr_max_distance,curr_height);
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
    cout<<s.MaxDistance(s.root);
}