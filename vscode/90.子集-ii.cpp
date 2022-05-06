/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) ;
    void dfs(int index,vector<int> nums,vector<int> &path,vector<vector<int> > &result);
    //path参数是一种subset
};

void Solution::dfs(int index,vector<int> nums,vector<int> &path,vector<vector<int> > &result)
{
    //终止条件
    if(index>=nums.size())
    {
        int i;
        int add_flag=1;
        for(i=0;i<result.size();i++)
        {
            if(path==result[i])
            {
                add_flag=0;
                break;
            }
        }
        if(add_flag)
        {
            result.push_back(path);
        }
    }
    else 
    {
        //判断重复的自己
        path.push_back(nums[index]);
        dfs(index+1,nums,path,result);
        path.pop_back();//回溯过程清空
        dfs(index+1,nums,path,result);
    }
}


vector<vector<int> > Solution::subsetsWithDup(vector<int>& nums) 
{
    vector< vector<int> > result;
    vector <int> path;
    dfs(0,nums,path,result);

    return result;
}

int main()
{
    Solution s;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    s.subsetsWithDup(arr);
}

// @lc code=end

