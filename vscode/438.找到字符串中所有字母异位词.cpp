/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need,window;
        vector<int> result;
        int i;
        for(i=0;i<p.size();i++)
        {
            need[p[i]]++;
        }
        int left=0;
        int right=0;
        int valid=0;

        while(right<s.size())
        {
            char c=s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                {
                    valid++;
                }
            }

            while(right-left==p.size())
            {
                if(valid==need.size())
                { 
                    result.push_back(left);
                }
                char d=s[left];
                left++;
                if(need.count(d))
                {
                    if(window[d]==need[d])
                    {
                        valid--;
                    }
                    window[d]--;
                }

            }
        }
        return result;
    }
};
// @lc code=end

