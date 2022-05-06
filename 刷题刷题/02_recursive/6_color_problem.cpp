#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums);
    void quicksort(vector<int>& nums,int low,int high);
    int partition(vector<int>& nums,int low,int high);

};

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
            swap(nums[++j],nums[i++]);
        }

        else if(nums[i]==pivot)
        {
            i++;
        }

        else if(nums[i]>pivot)
        {
            swap(nums[--k],nums[i]);
        }
    }
    return j+1;
    // cout<<j<<endl<<k<<endl
}


void Solution::quicksort(vector<int>& nums,int low,int high)
{
    if(low<high)
    {
        int mid=partition(nums,low,high);
        quicksort(nums,low,mid);
        quicksort(nums,mid+1,high);
    }
}

void Solution::sortColors(vector<int>& nums) 

{
    int i=0;//遍历节点
    int j=-1;//小于区域的右边届
    int k=nums.size();//大于区域的左边界
    int length=k;
    int pivot=1;
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
    cout<<j<<endl<<k<<endl;
}

int main()
{
    vector<int> a;
    // a.push_back(2);
    // a.push_back(0);
    // a.push_back(2);
    // a.push_back(1);
    // a.push_back(1);
    // a.push_back(0);
    a.push_back(3);
    a.push_back(5);
    a.push_back(6);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(2);
    a.push_back(6);
    a.push_back(9);
    a.push_back(0);
    a.push_back(5);
    a.push_back(3);
    Solution s;
    s.quicksort(a,0,a.size()-1);
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}