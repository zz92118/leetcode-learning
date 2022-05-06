#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
/*
搜索二叉树的性质 :中序遍历之后得到的会是一个升序数组
利用弟归和非递归的方法.
prev存储之前一个节点的数字
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
    class info
    {
    public:
        bool isBST;
        int min;
        int max;
        info(int x,int y,int z)
        {
            isBST=x;
            min=y;
            max=z;
        }
    };
    long long prev=INT64_MIN;
    Solution();
    TreeNode *root;
    bool isValidBST2(TreeNode* root);
    bool isValidBST(TreeNode* root);

    bool isValidBST3(TreeNode *root)
    {
        // cout<<process(root)->isBST;
        return process(root)->isBST;
    }
    info* process(TreeNode *curr);
};

Solution::info* Solution::process(TreeNode *curr)
{
    if(curr==nullptr)
    {
        return nullptr;
    }

    info* left_info=process(curr->left);
    info* right_info=process(curr->right);

    bool is_bst;
    int min_value=curr->val;
    int max_value=curr->val;
    //加工出自己的信息  判断空
    if(left_info)
    {
        min_value=min(left_info->min,curr->val);
        max_value=max(left_info->max,curr->val);
    }
    if(right_info)
    {
        min_value=min(right_info->min,min_value);
        max_value=max(right_info->max,max_value);
    }

    is_bst=false;

    if(
        ((left_info==nullptr) ? true : left_info->isBST)
        &&((right_info==nullptr) ? true : right_info->isBST)
        && ((left_info==nullptr) ? true : curr->val > left_info->max)
        && ((right_info==nullptr) ? true: curr->val < right_info->min)
    )
    {
        is_bst=true;
    }

    return new info(is_bst,min_value,max_value);

}



bool Solution::isValidBST(TreeNode* root)
{
    //中序递归方法 判断当前节点是否大于前一个节点
    bool flag;
    if(root==nullptr)
    {
        return true;
    }
    if(!isValidBST(root->left))
    {
        return false;
    }
    return isValidBST(root->left);
    if(root->val <= prev)
    {
        return false;
    }
    else 
    {
        prev=root->val;
        //这里不能return
        // return true;
    }
    if(!isValidBST(root->right))
    {
        return false;
    }


}


bool Solution::isValidBST2(TreeNode* root)
{
    TreeNode *curr;
    stack<TreeNode*> s;
    int prev_value=INT_MIN;
    curr=root;

    if(curr==nullptr)
    {
        return false;
    }
    while(!s.empty() || curr!=nullptr)
    {
        if(curr)
        {
            s.push(curr);
            curr=curr->left;
        }

        else if(!s.empty())
        {
            curr=s.top();
            s.pop();
            //
            if(curr->val < prev_value)
            {
                return false;
            }
            else{
                prev_value=curr->val;
            }
            // cout<<curr->val<<" ";
            curr=curr->right;
        }
    }
    return true;
    
}

Solution::Solution()
{
    TreeNode *n1= new TreeNode(5);
    TreeNode *n2= new TreeNode(4);
    TreeNode *n3= new TreeNode(6);
    TreeNode *n4= new TreeNode(3);
    TreeNode *n5= new TreeNode(7);

    n1->left=n2;
    n1->right=n3;
    n3->left=n4;
    n3->right=n5;
    // n2->left=n4;
    // n2->right=n5;
    // n3->left=n6;
    // n3->right=n7;
    root=n1;
}

int main()
{
    Solution s;
    cout<<s.isValidBST3(s.root);
    cout<<"eee";
}

