/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        stack<int> s;
        unordered_map<int,int> hashmap;//映射关系 \
        //nums2中：nums2[index]----->>>>下一个最大数的index 
        int i;
        for(i=nums2.size()-1;i>=0;i--)
        {
            //保持栈结构的单调性
            while(!s.empty() && nums2[i] >= nums2[s.top()])
            {
                s.pop();
            }
            hashmap[nums2[i]] = s.empty()? -1 : s.top();//s为empty则push -1
            s.push(i);//栈存放下标
        }

        for(i=0;i<nums1.size();i++)
        {
            int index=hashmap[nums1[i]];
            //hash map =-1;特殊处理一下
            
            result.push_back( index==-1 ? -1: nums2[index] );
        }

        return result;
    }
};
// @lc code=end

int main()
{
    vector<int> arr1;
    vector<int> arr2;

    arr1.push_back(4);
    arr1.push_back(1);
    arr1.push_back(2);
    
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(4);
    arr2.push_back(2);

    Solution s;
    s.nextGreaterElement(arr1,arr2);
    return 0;
    
}

