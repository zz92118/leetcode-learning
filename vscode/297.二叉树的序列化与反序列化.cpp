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
using namespace std;
/*
前序遍历的序列化 ： 依旧是采用前序的框架 在root=nullptr 加上应该加的字符串
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
        string res="";
        serialize_pre(root,res);
        return res;
    }

    void serialize_pre(TreeNode* root,string &res)
    {
        if(root==nullptr)
        {
            res+="#,";
            return ;
        }

        res+=to_string(root->val);
        res+=",";

        serialize_pre(root->left,res);
        serialize_pre(root->right,res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> dataArray;
        string str;

        for (int i=0;i<data.size()-1;i++) {
            char ch = data[i];
            if (ch == ',') {
                dataArray.push(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }

        if (!str.empty()) {
            dataArray.push(str);
            str.clear();
        }

        return deserialize_pre(dataArray);

    }

    TreeNode* deserialize_pre(queue<string>& sequence)
    {
        // if(sequence.empty())
        // {
        //     return nullptr;
        // }
        //消耗序列
        //base case
        if(sequence.front()=="#")
        {
            sequence.pop();
            return nullptr;
        }

        TreeNode *curr = new TreeNode((atoi(sequence.front().c_str())));
        sequence.pop();

        curr->left=deserialize_pre(sequence);
        curr->right=deserialize_pre(sequence);

        return curr;
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
    // n3->left=n4;
    // n3->right=n5;
    // n3->left=n6;
    // n3->right=n7;
    TreeNode* root=n1;

    Codec c;
    string s = c.serialize(root);
    TreeNode *result = c.deserialize(s);
    return 0;
}


