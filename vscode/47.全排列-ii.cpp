/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums);
    
    void dfs(vector<int> &nums,int index,vector<vector<int> >& result);//加入重复判断机制 
};

vector<vector<int> > Solution::permuteUnique(vector<int>& nums)
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
        unordered_set<int> hash_set;//重复判断机制
        //在index往后的位置做交换
        for(j=index;j<nums.size();j++)
        {
            if(!hash_set.count(nums[j]))
            {
                hash_set.insert(nums[j]);
                swap(nums[index],nums[j]);
                dfs(nums,index+1,result);
                swap(nums[index],nums[j]);
            }

        }
    }
}


// @lc code=end

