/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,j;
        i=0;
        j=s.size()-1;
        //单数 双数情况
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
// @lc code=end

