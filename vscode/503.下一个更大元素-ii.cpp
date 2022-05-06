/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*
单调栈基础上加一下环形数组
把原来的数组扩充成两倍 获得最后一个数的答案
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> temp(nums.size());//环形数组的下一个更大元素映射
        vector<int> result;
        // 把原来的数组扩充成两倍 获得最后一个数的答案

        for(int i=nums.size()*2-1;i>=0;i--)
        {
            //保持结构的单调性
            while(!s.empty() && nums[i%nums.size()] >= nums[s.top()])
            {
                s.pop();
            }
            temp[i%nums.size()] = s.empty() ? -1 : s.top();
            s.push(i%nums.size());
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int index = temp[i];

            int x=nums[index%nums.size()];

            result.push_back(index == -1 ? -1 : x);
        }

        return result;
    }
};
// @lc code=end


void RingArray()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    int n=arr.size();

    for(int i=0;i<100;i++)
    {
        cout<<arr[i%n]<<endl;
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);

    Solution s;
    s.nextGreaterElements(arr);
    return 0;
}
