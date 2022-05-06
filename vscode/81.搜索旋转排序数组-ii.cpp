/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right)
        {
            int mid = left + (right - left) / 2;
        
            if (nums[mid] == target)
            {
                return true;
            }

            if(nums[left] == nums[mid])
            {
                left++;
                continue;
            }

            if(nums[0] <= nums[mid] )//左边是升序数组
            {
                //在左边的部分
                if(target < nums[mid] && target >= nums [0] )
                {
                    right = mid -1;
                }
                else 
                {
                    left = mid + 1;
                }
            }

            else //右边是升序数组
            {
                //在右边的部分
                if( target > nums[mid] && target <= nums[nums.size()-1])
                {
                    left = mid + 1;
                }
                else 
                {
                    right = mid -1;
                }
            }           
        }  
        return false; 
    
    }

};
// @lc code=end

