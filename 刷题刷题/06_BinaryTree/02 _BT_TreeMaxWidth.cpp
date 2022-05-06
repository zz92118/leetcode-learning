#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
quene.size()为每一层的值


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
    Solution();
    TreeNode *root;
    vector<int> largestValues(TreeNode* root);
    vector<int> largestValues2(TreeNode* root);
    vector<int> levelmax(TreeNode* root);
};

vector<int> Solution::levelmax(TreeNode* root)
{
    //迭代实现
    //1.压入root 弹出并且打印
    //2.while循环 先右再左
    //bfs和前序遍历的唯一区别是stack和queue
    //有每一层的信息
    vector<int> a;
    queue<TreeNode*> q;
    TreeNode *curr;
    int current_level_max=INT64_MIN;
    if(root==nullptr)
    {
        return a;
    }
    q.push(root);
    while(!q.empty())
    {
        current_level_max=INT64_MIN;
        int level_size=q.size();//记录当前层的大小
        // cout<<level_size<<" ";


        // cout<<endl;
        while(level_size--)
        {
            curr=q.front();
            q.pop();
            // a.push_back(curr->val);
            // cout<<curr->val<<" ";
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            current_level_max=max(curr->val,current_level_max);
        }
        a.push_back(current_level_max);
    }
    return a;
}


vector<int> Solution::largestValues2(TreeNode* root)
{
    //迭代实现
    //1.压入root 弹出并且打印
    //2.while循环 先右再左
    //bfs和前序遍历的唯一区别是stack和queue
    //有每一层的信息
    vector<int> a;
    queue<TreeNode*> q;
    TreeNode *curr;
    int current_level_nodes=0;
    if(root==nullptr)
    {
        return a;
    }
    q.push(root);
    while(!q.empty())
    {
        int level_size=q.size();//记录当前层的大小
        cout<<level_size<<" ";


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
    }
    return a;
}

vector<int> Solution::largestValues(TreeNode* root)
{
    queue<TreeNode*> q;
        unordered_map<TreeNode*,int> level_map;
        vector<int> result;
        TreeNode *curr;
        int curr_level=1;//当前处理的层数
        int curr_node_level=1;//当前节点所在的层次
        int curr_levle_node=0;//当前层的节点数
        int max_node=0;//最大的节点数
        if(root==nullptr)
        {
            return result;
        }
        q.push(root);
        curr=root;
        level_map[curr]=1;
        curr_level=1;

        while(!q.empty())
        {
            curr=q.front();
            q.pop();
            // cout<<curr->val<<" ";
            curr_node_level=level_map[curr];//!!!!获取当前节点所在的层数
            curr_level=curr_node_level;
            //push
            if(curr->left)
            {
                q.push(curr->left);
                level_map[curr->left]=curr_node_level+1;//之前这里出错了 这个时候currlevel还没有更新,要用currnodevalue
            }
            if(curr->right)
            {
                level_map[curr->right]=curr_node_level+1;
                q.push(curr->right);
            }
            //统计节点 当前节点在当前层
            if(curr_level==curr_node_level)
            {
                curr_levle_node++;
            }
            else //如果来了一个下一层的节点
            {
                curr_level++;
                max_node=max(max_node,curr_levle_node);
                result.push_back(curr_levle_node);
                curr_levle_node=1;
            }

        }
        max_node=max(max_node,curr_levle_node);
        result.push_back(curr_levle_node);
        return result;
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
    vector<int> res=s.levelmax(s.root);
    cout<<endl;
    for(vector<int>::iterator i=res.begin();i<res.end();i++)
    {
        cout<<*i<<" ";
    }
    
    return 0;
}