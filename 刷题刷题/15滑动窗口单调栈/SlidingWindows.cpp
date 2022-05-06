/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        if(nums.size()==0 || nums.size()<k || k<1)
        {
            return result;
        }
        //加入的是下标!!!
        deque<int> SlidingWindow;
        int right=0;
        int left=0;
        for(right=0;right<nums.size();right++)
        {
            //right向右扩张的过程，一直pop确保队列是单调的 从队列尾部开始pop 
            while( !SlidingWindow.empty() && nums[SlidingWindow.back()] <= nums[right])
            {
                SlidingWindow.pop_back();
            }
            SlidingWindow.push_back(right);

            left=right-k+1;
            //left=0开始在窗口中加入值
            if(left<0)
            {
                continue;
            }
            //left向前，检查队列头的index和left是否相等，相等时pop front
            if(SlidingWindow.front()+1==left)
            {
                SlidingWindow.pop_front();
            }
            //加入result
            if(right >= k-1)
            {
                result.push_back(nums[SlidingWindow.front()]);
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(3);
    // arr.push_back(-1);
    // arr.push_back(-3);
    // arr.push_back(5);
    // arr.push_back(3);
    // arr.push_back(6);
    // arr.push_back(7);

    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(4);

    Solution s;
    s.maxSlidingWindow(arr,2);
}
