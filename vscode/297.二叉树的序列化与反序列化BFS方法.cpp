/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
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
#include<string>
#include<queue>
// #include<vector>
using namespace std;
/*
BFS的序列化 ： 采用BFS的框架，加入判空条件
BFS反序列化 也是BFS框架
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;

        //bfs 广度优先搜索遍历
        if(root==nullptr)
        {
            return "";
        }

        string res="";
        q.push(root);

        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if(curr==nullptr)
            {
                res+="#,";
                continue;//确保返回 不然死循环了
            }
            
            else 
            {
                res+=to_string(curr->val);
            }
            res+=",";
            q.push(curr->left);
            q.push(curr->right);
        }
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
        {
            return nullptr;
        }
        queue<string> dataArray;
        int i;
        string str="";
        for(i=0;i<data.size()-1;i++)
        {
            char ch=data[i];
            if(ch==',')
            {
                dataArray.push(str);
                str.clear();
                continue;
            }
            str.push_back(ch);
        }
        if(!str.empty())
        {
            dataArray.push(str);
            str.clear();
        }
        queue<TreeNode *> q;
        
        TreeNode *root = new TreeNode(atoi(dataArray.front().c_str()));
        dataArray.pop();
        q.push(root);

        while(!dataArray.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            string left = dataArray.front();
            dataArray.pop();

            if(left=="#")
            {
                curr->left=nullptr;
            }

            else 
            {
                curr->left = new TreeNode(atoi(left.c_str()));
                q.push(curr->left);
            }
            string right = dataArray.front();
            dataArray.pop();

            if(right=="#")
            {
                curr->right=nullptr;
            }
            else 
            {
                curr->right = new TreeNode(atoi(right.c_str()));
                q.push(curr->right);
            }
        }
        return root;

    }


    void bfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return ;
        }

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                TreeNode *curr=q.front();
                q.pop();
                cout<<curr->val<<" ";
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }

                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
            cout<<endl;

        }
    }






};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
int main()
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
    // n3->right=n5;
    // n3->left=n6;
    // n3->right=n7;
    TreeNode* root=n1;

    Codec c;
    // c.bfs(root);
    // cout<<c.serialize(root)<<endl;
    c.deserialize("1,2,3,#,4,#,#,#,#,");
    return 0;
}


