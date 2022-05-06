/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
快速排序每次确定一个数字的位置
如果一次partition为倒数第K个,那就找到

*/

class Solution {
public:
    // Solution();
    int partition(vector<int>& nums,int low,int high);
    int quick_select(vector<int>& nums,int low,int high,int k);

    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums,0,nums.size()-1,k);
    }
};

int Solution::quick_select(vector<int>& nums,int low,int high,int k)
{
    if(low<=high)
    {
        int index=partition(nums,low,high);
        if(index==nums.size()-k)
        {
            return nums[index];
        }

        else 
        {
            return index < (nums.size()-k) ? quick_select(nums, index + 1, high, k) : quick_select(nums, low, index-1, k);
        }
    }
    return -1;
}

int Solution::partition(vector<int>& nums,int low,int high)
{
        // < = >
    int i=low;//遍历节点
    int j=low-1;//小于区域的右边届
    int k=high+1;//大于区域的左边界
    int pivot=nums[low];
    while(i<k)
    {
        if(nums[i]<pivot)
        {
            swap(nums[j+1],nums[i]);
            j++;
            i++;
        }

        else if(nums[i]==pivot)
        {
            i++;
        }

        else if(nums[i]>pivot)
        {
            swap(nums[k-1],nums[i]);
            k--;
        }
    }
    return j+1;
    // cout<<j<<endl<<k<<endl
}
// @lc code=end

