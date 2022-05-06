/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include<vector>
#include<iostream>
using namespace std;
/*
快慢指针
slow fast
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        if(nums.size()==0)
        {
            return 0;
        }

        for(fast = 0; fast<nums.size(); fast++)
        {
            if(nums[fast]==val)
            {

            }
            else 
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

