/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // quicksort(nums,0,nums.size()-1);
        mergesort(nums,0,nums.size()-1);
        return nums;        
    }

    void mergesort(vector<int> &nums,int low,int high)
    {
        if(low<high)
        {
            int mid = (low+high)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,high);
        }
    }

    void merge(vector<int> &nums,int low,int high)
    {
        int i,j,k;
        vector<int> b;
        int mid = (low+high)/2;

        i=low;
        j=mid+1;

        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                b.push_back(nums[i]);
                i++;
            }
            else if(nums[i]>nums[j])
            {
                b.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid)
        {
            b.push_back(nums[i]);
            i++;
        }
        while(j<=high)
        {
            b.push_back(nums[j]);
            j++;
        }

        for(i=0;i<b.size();i++)
        {
            nums[i+low]=b[i];
        }

    }

    int partition(vector<int> &nums,int low,int high)
    {
        int i=low;
        int j=low-1; //小于等于区的右侧边界 
        int k=high+1; //大于等于区的左侧边界 
        int pivot=nums[low];

        while(i<k)
        {
            if(nums[i]<pivot)
            {
                swap(nums[i],nums[j+1]);
                i++;
                j++;
            }
            else if(nums[i]==pivot)
            {
                i++;
            }
            else if(nums[i]>pivot)
            {
                swap(nums[i],nums[k-1]);
                k--;
            }
        }

        return j+1;
    }

    void quicksort(vector<int> &nums,int low,int high)
    {
        if(low<high)
        {
            int par = partition(nums,low,high);
            quicksort(nums,low,par-1);
            quicksort(nums,par+1,high);
        }
    }

};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(1);

    Solution s;
    s.sortArray(arr);
    return 0;
}
