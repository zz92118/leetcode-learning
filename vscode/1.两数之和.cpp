/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
/*
复杂度分析 O(N*2)
//主要是找 target - x的复杂度 从 N 优化到常数项1
find 方法的使用
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hashtable;//数字----》下标
        int i;
        for(i=0;i<nums.size();i++)
        {
            unordered_map<int,int>::iterator it = hashtable.find(target - nums[i]);

            if(it!=hashtable.end())
            {
                result.push_back(i);
                result.push_back(it->second);//加入hahs的value
            }
            // if(hashtable.find(target - nums[i])!=hashtable.end())
            // {
            //     result.push_back(i);
            //     result.push_back(hashtable[target - nums[i]]);
            //     return result;
            // }
            else 
            {
                hashtable[nums[i]]=i;
            }
        }

        return result;
    }
};
// @lc code=end

vector<int> twoSum(vector<int>& nums, int target) {
    int i,j;
    vector<int> res;
    for(i=0;i<nums.size();i++)
    {
        for(j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(15);

    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
    {
        cout<<*i<<endl;
    }

    Solution s;
    s.twoSum(arr,9);
    return 0;
}
