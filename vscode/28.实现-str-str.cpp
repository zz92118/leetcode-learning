/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //暴力
    int strStr(string haystack, string needle) ;
    vector<int> getnextArray(string str2);

};

int Solution::strStr(string str1,string str2)
{
    if(str1.length()<str2.length())
    {
        return -1;            
    }
    if(str2=="")
    {
        return 0;
    }
    int i1=0;
    int i2=0;
    //获取next数组
    vector<int> next=getnextArray(str2);

    while(i1<str1.length() && i2<str2.length())
    {
        //1.向前匹配
        if(str1[i1]==str2[i2])
        {
            i1++;
            i2++;
        }
        // str2无法往前跳了，str1向后
        else if(next[i2]==-1)
        {
            i1++;
        }
        //next数组：对应str2往前跳 这一步是优化！！！！！
        else 
        {
            i2=next[i2];
        }
    }
    if(i2==str2.length())
    {
        return i1-i2;
    }
    return -1;

}

vector<int> Solution::getnextArray(string str2)
{
    //+1+1+1+1+！！！！！！！！！！！！！！！！！！！！
    vector<int> next(str2.length()+1); 
    if(str2.length()==0)
    {
        next[0]=-1;
        return next;
    }

    //人为规定next[0]和next[1]
    next[0]=-1;
    next[1]=0;

    int i=2;//next数组的位置
    int cn=0;
    //cn是相等前缀和的下一个位置
    //用cn的位置和i-1的位置比
    //也代表i-1位置的信息是多少next[i-1]
    while(i<next.size())
    {
        if(str2[i-1]==str2[cn])

        {
            //i的信息由i-1和cn位置的信息得到
            next[i]=cn+1;
            i++;
            cn++;
            //被下一部分的i利用，cn和i都++
        }
        //cn往前跳 同KMP算法主过程
        else if(cn>0)
        {
            cn=next[cn];
        }
        //没有前后缀
        else
        {
            next[i]=0;
            i++;
        }
    }

    return next;
    
}
// @lc code=end
int main()
{
    Solution s;
    cout<<s.strStr("a","a")<<endl;
}

//暴力方法
    int strStr(string haystack, string needle) {
        int i;
        int j;
        if(haystack.size()<needle.size())
        {
            return -1;            
        }
        if(needle=="")
        {
            return 0;
        }

        for(i=0;i<=haystack.size()-needle.size();i++)
        {
            int k=i;
            for(j=0;j<needle.size();j++)
            {
                if(haystack[k]==needle[j])
                {
                    k++;
                    continue;
                }
                else 
                {
                    break;
                }
            }
            if(j==needle.size())
            {
                return i;
            }
        }  
        return -1; 
    }