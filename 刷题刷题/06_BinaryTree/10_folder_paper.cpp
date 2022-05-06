#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(int i,int n, bool down)
{
    if(i>n)
    {
        return;
    }
    print(i+1,n,true);
    if(down)
    {
        cout<<"down"<<" ";
    }
    else
    {
        cout<<"up"<<" ";
    }
    print(i+1,n,false);
}


void paper_folding(int n)
{
    print(1,n,true);
}


int main()
{
    paper_folding(4);
}