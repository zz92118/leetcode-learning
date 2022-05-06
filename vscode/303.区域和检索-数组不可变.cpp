/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


class NumArray {
public:
    vector<int> sums;//(n+1长度)
    NumArray(vector<int>& nums) {
        int i;
        sums.resize(nums.size()+1);
        sums[0]=0;
        for(i=0;i<nums.size();i++)
        {
            //构造前缀和数组
            sums[i+1]=sums[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(-5);
    arr.push_back(2);
    arr.push_back(-1);

    NumArray *n= new NumArray(arr);
}

