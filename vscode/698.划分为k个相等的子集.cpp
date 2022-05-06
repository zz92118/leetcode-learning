/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
剪枝函数的设计
一开始数据的预处理，先进行一个sort

*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int i;
        //只有整除才能Partition
        int sum=0;
        sort(nums.rbegin(),nums.rend());
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%k!=0)
        {
            return false;
        }

        int target = sum/k;
        vector<int> subset_num ;//dim为K的数组,将原属组分成K的子集
        for(i=0;i<k;i++)
        {
            subset_num.push_back(0);
        }

        bool flag = dfs(nums,k,0,target,subset_num);
        return flag;

    }

    bool dfs(vector<int>& nums,int k,int index,int target,vector<int> &subset)
    {
        if(index>nums.size())
        {
            //种植条件1
            return false;
        }

        else 
        {
            //判断有没有
            if(index==nums.size())
            {
                int i;
                for(i=0;i<k;i++)
                {
                    if(subset[i]!=target)
                    {
                        return false;
                    }
                }
                return true;
                //K个子集的sum相等
            }
            else 
            {
                int i;
                //将nums[index]放入K个桶
                for(i=0;i<k;i++)
                {
                    if(subset[i]+nums[index]>target)
                    {
                        continue ;
                    }
                    subset[i]+=nums[index];
                    if(dfs(nums,k,index+1,target,subset))
                    {
                        return true;
                    }
                    subset[i]-=nums[index];//回溯
                }
            }
            //for pass,不会执行到的
            return false;
        }
    }
};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(1);


    Solution s;
    cout<<s.canPartitionKSubsets(arr,2)<<endl;
    return 0;
}

