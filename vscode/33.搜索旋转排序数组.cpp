/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
/*
旋转后的两个部分都是升序数组
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right)
        {
            int mid = left + (right - left) / 2;
        
            if (nums[mid] == target)
            {
                return mid;
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
        return -1; 
    }
};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    Solution s;
    cout<<s.search(arr,0)<<endl;
    return 0;
}

