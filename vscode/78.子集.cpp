/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) ;
    void dfs(int index,vector<int> nums,vector<int> &path,vector<vector<int> > &result);
};

void Solution::dfs(int index,vector<int> nums,vector<int> &path,vector<vector<int> > &result)
{
    //终止条件
    if(index>=nums.size())
    {
        result.push_back(path);
    }
    else 
    {
        path.push_back(nums[index]);
        dfs(index+1,nums,path,result);
        path.pop_back();//回溯过程清空
        dfs(index+1,nums,path,result);
    }
}


vector<vector<int> > Solution::subsets(vector<int>& nums) 
{
    vector<vector<int> > result;
    vector <int> path;
    dfs(0,nums,path,result);
    return result;
}

// @lc code=end

