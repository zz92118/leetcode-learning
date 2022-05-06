/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
/*
slow fast 快慢指针

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int fast=0;

        while(fast<nums.size())
        {
            if(nums[fast]!=0)
            {
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }

        int i;
        for(i=slow;i<nums.size();i++)
        {
            nums[i]=0;
        }

    }
};
// @lc code=end

