/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

/*
对于某个位置 right，有 sums[right+1] - sums[left] == k的时候 添加一个可行解
利用hashmap找到有几个前缀和为 sums[right+1]-k的数组,
优化到复杂度为O（N）的级别


*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sums;//前缀和 ---> 前缀和出现的次数
        int result=0;
        int sums_of_i=0;
        int i;
        sums[0]=1;
        for(i=0;i<nums.size();i++)
        {
            sums_of_i+=nums[i];
            int target = sums_of_i - k;
            if(sums.count(target))
            {
                result+=sums[target];
            }
            sums[sums_of_i]++;
        }
        return result;
    }

};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(-1);
    arr.push_back(0);
    Solution s;
    cout<<s.subarraySum(arr,0);
}
// 暴力解法
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1);
        int i,j;
        int result=0;
        sums[0]=0;
        //构造前缀和
        for(i=0;i<nums.size();i++)
        {
            sums[i+1]=sums[i]+nums[i];
        }
    
        for(i=0;i<nums.size();i++)
        {
            for(j=i;j<nums.size();j++)
            {
                if(sums[j+1]-sums[i]==k)
                {
                    result++;
                }
            }
        }
        return result;

    }