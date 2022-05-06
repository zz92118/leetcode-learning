#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int can_par=0;
    bool canPartition(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        process(nums,0,arr1,arr2);
        if(can_par>0)
        {
            return true;
        }
        return false;
    }
    void process(vector<int>& nums,int index,vector<int> &arr1,vector<int> &arr2);
    int get_sum(vector<int> arr);
};


int Solution::get_sum(vector<int> arr)
{
    int sum=0;
    for(vector<int>::iterator i=arr.begin();i<arr.end();i++)
    {
        sum+=*i;
    }
    return sum;
}

void Solution::process(vector<int>& nums,int index,vector<int> &arr1,vector<int> &arr2)
{
    if(index>=nums.size())
    {
        if(get_sum(arr1)==get_sum(arr2))
        {
            can_par++;
        }
        return ;
    }

    else 
    {
        arr1.push_back(nums[index]);
        process(nums,index+1,arr1,arr2);
        arr1.pop_back();

        arr2.push_back(nums[index]);
        process(nums,index+1,arr1,arr2);
        arr2.pop_back();
    }
}
