/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<string>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int left=0;
        int right=0;
        int length=0;

        while(right<s.length())
        {
            char c = s[right];
            right++;
            window[c]++;
            //收缩条件
            while(window[c]>1)
            {
                char d = s[left];
                left ++ ; 
                window[d]--;
            }
            length=max(length,right-left);
        }
        return length;
    }
};
// @lc code=end

