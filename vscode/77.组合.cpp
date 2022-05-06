/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        int i;
        vector<int> curr;
        dfs(n,k,1,res,curr);//可变参数为当前选的数值 从1开始dfs
        return res;
    }

    void dfs(int n,int k,int index,vector<vector<int> >& result,vector<int> &curr)
    {
        //边界条件是每一个组合到了给定的K的大小
        if(curr.size()>=k)
        {
            result.push_back(curr);
        }
        else
        {
            int i;
            for(i=index;i<=n;i++)
            {
                curr.push_back(i);
                dfs(n,k,i+1,result,curr);
                curr.pop_back();
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.combine(4,2);
}

