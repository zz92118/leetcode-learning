/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
一个数字可以被无限次的选择
dfs(result,candidates,combination,index,rest-candidates[index]);
dfs过程
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        //一个数字可以被无限次的选择
        vector<vector<int> >res;
        vector<int> com;
        dfs(res,candidates,com,0,target);
        return res;
    }
    void dfs(vector<vector<int> > &result,vector<int>& candidates,vector<int> &combination,int index,int rest)
    {
        if(rest<0 || index>=candidates.size())
        {
            return ;
        }
        else 
        {
            if(rest==0)
            {
                result.push_back(combination);
            }
            else 
            {
                //不选择
                dfs(result,candidates,combination,index+1,rest);
                //选择,每个位置的值可以重复选择
                combination.push_back(candidates[index]);
                dfs(result,candidates,combination,index,rest-candidates[index]);
                combination.pop_back();//回溯过程
            }
            return ;
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    s.combinationSum(arr,7);
    return 0;
}
// @lc code=end

