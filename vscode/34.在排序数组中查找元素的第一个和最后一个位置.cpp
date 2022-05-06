/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target);
    int searchLeftRange(vector<int>& nums, int target);
    int searchRightRange(vector<int>& nums, int target);
    int binarySearch(vector<int>& nums, int target);
};

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
    vector<int> result(2);
    result[0] = searchLeftRange(nums,target);
    result[1] = searchRightRange(nums,target);   
    return result;
}

int Solution::searchLeftRange(vector<int>& nums, int target)
{
    int left=0;
    int right = nums.size()-1;
    while(left<=right)//left right 是相等的
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target )//缩进右边界 
        {
            right=mid-1;
        }

        else if(nums[mid] < target)
        {
            left=mid+1;
        }

        else if(nums[mid] > target)
        {
            right=mid-1;
        }
    }
    //检查越界
    if(left>=nums.size() || nums[left]!=target)
    {
        return -1;
    }

    return left;
}

int Solution::searchRightRange(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target)//锁紧左边界
        {
            left=mid+1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else if(nums[mid]>target)
        {
            right=mid-1;
        }
    }

    if(right<0 || nums[right]!=target)
    {
        return -1;
    }
    return right;
}

int Solution::binarySearch(vector<int>& nums, int target)
{
        int left = 0;
        int right =nums.size()-1;

        while(left<=right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1 ;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1 ;
            }
        }
        return -1;
}

// @lc code=end

