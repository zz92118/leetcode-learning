/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums);
    
    void dfs(vector<int> &nums,int index,vector<vector<int> >& result);
};

vector<vector<int> > Solution::permute(vector<int>& nums)
{
    vector<vector<int> > res;
    dfs(nums,0,res);
    return res;
}

void Solution::dfs(vector<int> &nums,int index,vector<vector<int> > &result)
{
    if(index>=nums.size())
    {
        result.push_back(nums);
    }
    else 
    {
        int j;
        //在index往后的位置做交换
        for(j=index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            dfs(nums,index+1,result);
            swap(nums[index],nums[j]);
        }
    }
}


// @lc code=end

