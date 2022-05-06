/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int i;
        int n = nums.size();
        for(i=0;i<n;i++)
        {
            vector<vector<int> > tuples = threeSum(nums,i+1,target-nums[i]); //twoSum得到的所有可能解 这里是i+1 因为不包括当前元素
            for(vector<vector<int> >::iterator tuple=tuples.begin();tuple!=tuples.end();tuple++)
            {
                // vector<int> r=*tuple;
                (*tuple).push_back(nums[i]);
                res.push_back(*tuple);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果 因为 twoSum(target-nums[i])
            while(i<n-1 && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return res;
    }

    vector<vector<int> > threeSum(vector<int>& nums,int start,int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int i;
        int n = nums.size();
        for(i=start;i<n;i++)
        {
            vector<vector<int> > tuples = twoSum(nums,i+1,target-nums[i]); //twoSum得到的所有可能解 这里是i+1 因为不包括当前元素
            for(vector<vector<int> >::iterator tuple=tuples.begin();tuple!=tuples.end();tuple++)
            {
                // vector<int> r=*tuple;
                (*tuple).push_back(nums[i]);
                res.push_back(*tuple);
            }
            while(i<n-1 && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return res;
    }

    vector<vector<int> > twoSum(vector<int>& nums,int start,int x) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int> > res;
        int low=start;
        int high=nums.size()-1;
        while(low<high) //< 不然会陷入死循环的
        {
            int left=nums[low];
            int right=nums[high];
            if(left+right==x)
            {
                temp.push_back(nums[low]);
                temp.push_back(nums[high]);
                res.push_back(temp);
                temp.clear();
                //跳过全部重复的元素
                while(low<=high && left==nums[low])
                {
                    low++;
                }
                while(low<=high && right==nums[high])
                {
                    high--;
                }
            }
            else if(left+right>x)
            {
                high--;
            }
            else if(left+right<x)
            {
                low++;
            }

        }
        return res;
    }
};
// @lc code=end

