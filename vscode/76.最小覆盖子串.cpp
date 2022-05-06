/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        //left 左开 right右闭
        int left=0;
        int right=0;
        int valid=0;//代表
        //记录最小串的索引和长度s
        int start =0;
        int len=INT_MAX;
        //初始化need数组
        for(int i=0;i<t.length();i++)
        {
            need[t[i]]++;
        }
        //一直到数组右边届  
        while(right<s.size())
        {
            //获取当前字符 
            char c=s[right];
            //窗口右移
            right++;
            //窗口数据更新
            if(need.count(c))
            {
                window[c]++;//如果没有这条记录,对应的map char-->int 为0
                if(window[c]==need[c])
                {
                    valid++;//有一个字符得到了匹配
                }
            }

            // debug: 
            // cout<<left<<right<<endl;

            //判断left窗口收缩 
            while(valid==need.size())//说明T可以被覆盖
            {
                //更新最小覆盖字符串
                if( right - left < len )
                {
                    start=left;
                    len = right-left;
                }
                //获取当前字符
                char d = s[left];
                //左移窗口
                left++;
                if(need.count(d))//只有d和需要得到的字符串有关的时候才更新window
                {
                    if(window[d] == need[d])
                    {
                        valid--;
                    }
                    window[d]--;
                }

            }
        }
        if(len==INT_MAX)
        {
            return "";
        }
        else 
        {
            return s.substr(start,len);
        }

    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.minWindow("ADOBECODEBANC","ABC");
}

