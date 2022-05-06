/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int i;
        int n = nums.size();
        for(i=0;i<n;i++)
        {
            vector<vector<int> > tuples = twoSum(nums,i+1,0-nums[i]); //twoSum得到的所有可能解 这里是i+1 因为不包括当前元素
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

int main()
{
    vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(3);

    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-1);
    arr.push_back(4);
    // arr.push_back(3);
    Solution s;
    s.twoSum(arr,0+1,0);
}

