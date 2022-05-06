/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
};
// @lc code=end
int main()
{
    vector<int> arr;
    arr.push_back(2); 
    arr.push_back(5);
    Solution s;
    cout<<s.search(arr,5)<<endl;
}



class SolutionRecursive {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            return nums[0]==target ? 0 : -1;
        }
        int index = binarysearch(nums,0,nums.size()-1,target);
        return index ;
    }
    int binarysearch(vector<int>& nums,int low,int high,int target)
    {
        if(low<=high)
        {
            int mid = (low+high) / 2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                return binarysearch(nums,mid+1,high,target);
            }

            else if( nums[mid] > target)
            {
                return binarysearch(nums,0,mid-1,target);
            }
        }
        return -1;
    }
};