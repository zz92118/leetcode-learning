#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
1.
HashMap map: 记录下每个节点的父节    curr----curr->father
HashSet set: 记录下o1的父节点路径
o2在路径中继续寻找 直到根节点
2.
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
    //o1 o2 一定属于head为头的树
    TreeNode *root;

    unordered_map<TreeNode*,TreeNode*> father_map;
    unordered_set<TreeNode*> father_path_set;
    Solution();
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //优化过的代码
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        process(root);
        father_map[root]=root;//根结点的父亲是他自己
        TreeNode *curr;
        TreeNode *father;
        curr=p;
        while(curr!=father_map[curr])//当前不是头节点
        {
            father=father_map[curr];
            father_path_set.insert(father);
            curr=father;
        }
        father_path_set.insert(p);//放自己

        curr=q;
        // father=curr;
        while(curr!=father_map[curr])
        {
            //先判断当前节点是不是
            if(father_path_set.count(curr))
            {
                //在p的路径中有了q的父节点
                return curr;
            }
            curr=father_map[curr];
            // father=father_map[curr];

        }
        return curr;
        

    }
    void process(TreeNode *curr);//先序遍历
};

Solution::Solution()
{
    TreeNode *n1= new TreeNode(6);
    TreeNode *n2= new TreeNode(2);
    TreeNode *n3= new TreeNode(8);
    TreeNode *n4= new TreeNode(0);
    TreeNode *n5= new TreeNode(4);
    TreeNode *n6= new TreeNode(7);
    TreeNode *n7= new TreeNode(9);
    TreeNode *n8= new TreeNode(3);
    TreeNode *n9= new TreeNode(5);

    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n5->left=n8;
    n5->right=n9;
    n3->left=n6;
    n3->right=n7;
    root=n1;
}

void Solution::process(TreeNode *curr)
{
    //先序处理过程
    //先把当前节点的左右节点加入
    if(curr==nullptr)
    {
        return ;
    }

    if(curr->left)
    {
        father_map[curr->left]=curr;
    }
    if(curr->right)
    {
        father_map[curr->right]=curr;
    }

    process(curr->left);
    process(curr->right);

}

int main()
{
    Solution s;
    cout<<s.lowestCommonAncestor(s.root,s.root->left,s.root->left->right)->val;
    return 0;
}