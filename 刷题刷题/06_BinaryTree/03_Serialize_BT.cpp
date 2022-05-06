#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
序列化过程: 每一步都进行序列话,包括null
反序列化:   每一步都消耗序列,只有当当前的序列为null的时候才简历子树节点
bfs:bfs框架循环 
前序:递归建立子树节点
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
    Solution();
    TreeNode *root;
    //前序序列化
    queue<string>  pre_serialize(TreeNode *root);
    TreeNode* pre_unserialize(queue<string> &q);//利用 序列递归建立二叉树
    void pre_serialize_process(TreeNode *root,queue<string> &q);//修改需要加饮用

    //bfs序列化
    queue<string> bfs_serialize(TreeNode *root);
    TreeNode* bfs_unserialize(queue<string> &q);
    TreeNode* generate_node(string val);//返回一个节点
    //前序输出节点验证
    void preorder(TreeNode *root);
};

TreeNode* Solution::generate_node(string val)
{
    if(val=="NULL")
    {
        return nullptr;
    }
    else{
        TreeNode *node = new TreeNode;
        node->val=stoi(val);
        node->left=nullptr;
        node->right=nullptr;
        return node;
    }
}


TreeNode* Solution::bfs_unserialize(queue<string> &serialize_list)
{
    /*
    反序列化的时候 使用bfs框架
    curr节点利用generatenode生成
    一直消耗序列同时生成节点 
    只有消耗序列当前的节点不等于空的时候,push子树
    */
    queue<TreeNode*> q;
    //如果列表是空的
    if(serialize_list.empty())
    {
        return nullptr;
    }
    //处理根节点
    string curr_val=serialize_list.front();
    serialize_list.pop();
    TreeNode *root;
    root = generate_node(curr_val);
    if(root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        TreeNode *curr;
        curr = q.front();
        q.pop();
        //消耗序列
        if(serialize_list.size()>0)
        {
            //序列一直消耗 只进行序列化
            curr->left=generate_node(serialize_list.front());
            serialize_list.pop();
            curr->right=generate_node(serialize_list.front());
            serialize_list.pop();
            //只有非空的时候push子树
            if(curr->left)
            {
                q.push(curr->left);//序列化的同时push queue
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }

    }
    return root;
}


queue<string> Solution::bfs_serialize(TreeNode *root)
{
    queue<string> result;
    queue<TreeNode*> q;
    if(root==nullptr)
    {
        return result;
    }
    q.push(root);
    result.push(to_string(root->val));
    while(!q.empty())
    {
        TreeNode *curr;
        int size=q.size();
        //都加入加入序列
        //只有子树不为null才加入队列
        while(size--)
        {
            curr=q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
                result.push(to_string(curr->left->val));//序列化的同时push进入queue
            }
            else
            {
                result.push("NULL");//只进行序列话
            }
            if(curr->right)
            {
                q.push(curr->right);
                result.push(to_string(curr->right->val));
            }
            else
            {
                result.push("NULL");
            }
        }
    }

    return result;
}


void Solution::preorder(TreeNode *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

TreeNode* Solution::pre_unserialize(queue<string> &serialize_list)
{
    TreeNode *root;
    //持续到序列为空
    if(!serialize_list.empty())
    {
        //vector也可以操作,index每次向后移动一位
        string temp=serialize_list.front();
        serialize_list.pop();

        if(temp=="NULL")
        {
            return nullptr;
        }
        //递归建立　
        root = new TreeNode();
        root->val= stoi(temp);
        root->left = pre_unserialize(serialize_list);
        root->right = pre_unserialize(serialize_list);
    }
    return root;
}



queue<string> Solution::pre_serialize(TreeNode *root)
{
    queue<string> res;
    pre_serialize_process(root,res);
    return res;
}


void Solution::pre_serialize_process(TreeNode *root,queue<string> &q)
{
    if(root==nullptr)
    {
        q.push("NULL");
        return ;
    }
    {
        q.push(to_string(root->val));
        pre_serialize_process(root->left,q);
        pre_serialize_process(root->right,q);
    }
}





Solution::Solution()
{
    TreeNode *n1= new TreeNode(1);
    TreeNode *n2= new TreeNode(2);
    TreeNode *n3= new TreeNode(3);
    TreeNode *n4= new TreeNode(4);
    TreeNode *n5= new TreeNode(5);
    // TreeNode *n6= new TreeNode(6);
    // TreeNode *n7= new TreeNode(7);
    n1->left=n2;
    n1->right=n3;
    n2->right=n4;
    n3->left=n5;
    // n3->left=n6;
    // n3->right=n7;
    root=n1;
}

int main()
{
    Solution s;
    queue<string> q;
    q=s.bfs_serialize(s.root);// 序列化结果
    // while(!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    TreeNode *res=s.bfs_unserialize(q);
    // s.preorder(res);

    queue<string> test;
    q=s.bfs_serialize(res);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}