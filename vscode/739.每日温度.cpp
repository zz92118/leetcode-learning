/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> temp_(temperatures.size());//比当前数大的下一个最近的数字 
        vector<int> result;
        int i;

        for(i=temperatures.size()-1;i>=0;i--)
        {
            //保持单调性
            while(!s.empty() && temperatures[i] >= temperatures[s.top()])
            {
                s.pop();
            }
            temp_[i] = s.empty() ? -1 : s.top();
            s.push(i);//加入下标
        }

        for(i=0;i<temperatures.size();i++)
        {
            int x=temp_[i]-i;
            result.push_back(x<0? 0 : x);
        }
        return result;
    }
};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(73);
    arr.push_back(74);
    arr.push_back(75);
    arr.push_back(71);
    arr.push_back(69);
    arr.push_back(72);
    arr.push_back(76);
    arr.push_back(73);

    Solution s;
    s.dailyTemperatures(arr);

}