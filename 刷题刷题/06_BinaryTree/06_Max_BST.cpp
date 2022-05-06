#include<iostream>
#include<algorithm>

using namespace std;
/*
处理信息加入nullptr操作
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

class Solution
{
public:
    TreeNode *root;
    class Info
    {
    public:
        bool is_BST;//curr的子树是不是一颗搜索二叉树
        int max;//当前的最大值
        int min;//当前的最小值
        int max_sub_size;//最大的BST的大小
        Info(int i,int ma,int mi,int mss)
        {
            is_BST=i;
            max=ma;
            min=mi;
            max_sub_size=mss;
        }
    };

    Solution();
    Info* process(TreeNode *curr);


};

Solution::Info* Solution::process(TreeNode *curr)
{
    //加上空操作
    if(curr==nullptr)
    {
        return nullptr;
    }

    Info* left_info=process(curr->left);
    Info* right_info=process(curr->right);

    //要加工的信息
    int max_value=INT64_MIN;
    int min_value=INT64_MAX;
    bool is_BST=false;
    int max_sub_size=0;

    if(left_info!=nullptr)
    {
        min_value=min(min_value,left_info->min);
        max_value=max(max_value,left_info->max);
    }
    if(right_info!=nullptr)
    {
        max_value=max(max_value,right_info->max);
        min_value=min(min_value,right_info->max);
    }

    //1.BST的建立与curr无关 
    
    //那么max size是左右的最大值 ,is_BST=false;
    if(left_info!=nullptr)
    {
        max_sub_size=left_info->max_sub_size;
    }
    if(right_info!=nullptr)
    {
        max_sub_size=max(max_sub_size,right_info->max_sub_size);
    }
    //2.BST的建立与curr无关
    //那么max_size是以curr为头的二叉树节点个数
    //!!!!!!判空
    if( (left_info==nullptr ? true : left_info->is_BST) //左树是BST
    && (right_info==nullptr ? true : right_info->is_BST) //右边是BST
    && (left_info==nullptr ? true : left_info->max < curr->val)//左边小于右边
    && (right_info==nullptr ? true : right_info->min > curr->val) )//
    {
        max_sub_size=
        (left_info==nullptr ? 0:left_info->max_sub_size)//判空
        +
        (right_info==nullptr ? 0:right_info->max_sub_size)
        +1;
        is_BST = true;
    }

    return new Info(is_BST,max_value,min_value,max_sub_size);

}