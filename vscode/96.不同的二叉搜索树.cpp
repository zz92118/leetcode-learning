/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

/*
这个咋操作、
利用dfs+备忘录的方法 
函数签名：count_dfs(int low,int high)
low>high 的时候 空节点也属于一种情况
*/

// class TreeNode{
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int numTrees(int n) {
        vector<vector<int> > dp;
        int i;
        vector<int> temp;
        for(i=0;i<=n;i++)
        {
            temp.push_back(0);
        }
        for(i=0;i<=n;i++)
        {
            dp.push_back(temp);
        }
        int nums=count_dfs(1,n,dp);
        return nums;
    }

    int count_dfs(int low,int high,vector<vector<int> > &dp)
    {
        if(low>high)
        {
            //空节点也属于一种情况
            return 1;
        }

        if(dp[low][high]!=0)
        {
            return dp[low][high];
        }


        int i;
        int nums=0;//每次进入count_dfs的时候节点要清零
        for(i=low;i<=high;i++)
        {
            int left = count_dfs(low,i-1,dp);
            int right = count_dfs(i+1,high,dp);
            nums += left*right;
        }
        dp[low][high]=nums;
        return dp[low][high];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.numTrees(3);
}

