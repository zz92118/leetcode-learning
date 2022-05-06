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



int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(3);

    Solution s;
    cout<<s.findKthLargest(a,2);
}
