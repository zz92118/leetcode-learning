#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/*
左边产生的逆序对+右边+merge过程的逆序对
*/
class Solution {
public:
    int pair_num=0; 
    int reversePairs(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return pair_num;
    }

    void merge_sort(vector<int>& nums,int low,int high);
    void merge(vector<int>& nums,int low,int high);
};


void Solution::merge_sort(vector<int>& nums,int low,int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        //逆序对的个数：
        //两个mergesort子过程和一个merge的过程共同产生的
        //如果设计成int类型的函数要把三个部分加起来
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(nums,low,high);
    }
}

void Solution::merge(vector<int>& nums,int low,int high)
{
    int mid;
    vector<int> help;
    mid = (low+high)/2;
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high)
    {
        if(nums[i]<=nums[j])
        {
            help.push_back(nums[i]);
            i++;
        }

        else 
        {
            help.push_back(nums[j]);
            j++;
            pair_num+=mid+1-i;//产生逆序对 在全局变量加
        }
    }
    while(i<=mid)
    {
        help.push_back(nums[i]);
        i++;
    }
    while(j<=high)
    {
        help.push_back(nums[j]);
        j++;
    }
    //这里从low加到high help数组不一样
    for(i=0;i<help.size();i++)
    {
        nums[i+low]=help[i];
    }
}


int main()
{
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(4);
    // arr.push_back(2);

    Solution s;
    s.reversePairs(arr);

    for(vector<int>::iterator i=arr.begin();i<arr.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<s.pair_num;
    return 0;
}

