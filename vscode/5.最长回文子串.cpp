/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int length=0;
        int max_index=0;
        //筛选边界条件和预处理工作
        if(s.length()==0)
        {
            return "";
        }
        if(s.length()==1)
        {
            return s;
        }
        //扩充
        string str="#";
        int i;
        for(i=0;i<s.length();i++)
        {
            str+=s[i];
            str+="#";
        }
        vector<int> radis_arr(str.length());//回文半径数组
        int c=-1;//回文最大扩充的中心
        int r=-1;//回文最大的边界为R-1位置 R是终止位置

        for(i=0;i<str.length();i++)
        {
            //不用验证的区域
            if(r>i)
            {
                int i_=2*c-i;
                radis_arr[i]=min(radis_arr[i_],r-i);
                //i_的半径和R-I的最小值
            }
            else {
                radis_arr[i]=1;
            }
            //需要验证的区域ß
            while(i+radis_arr[i]<str.length() && i-radis_arr[i]>-1)
            {
                //可以继续扩充 对应情况1和2.3
                if(str[i+radis_arr[i]]==str[i-radis_arr[i]])
                {
                    radis_arr[i]++;
                }
                //对应情况2.2和2.1 不能继续扩充
                else 
                {
                    break;
                }
            }

            //更新r和c同步更新的
            if(i+radis_arr[i]>r)
            {
                r = i+radis_arr[i];
                c = i;
            }
            length=max(length,radis_arr[i]);
        }

        // return length-1;//因为多出一个#所以要-1
        string res="";
        //分析完之后发现奇数偶数的结论是一样的可以合并
        int left= max_index - radis_arr[max_index]+2;
        int right = max_index + radis_arr[max_index]-2;
        for( i = left ;i <= right;i+=2)
        {
            res+=str[i];
        }
    
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.longestPalindrome("1132310")<<endl;
}


// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int length=0;
//         //筛选边界条件
//         if(s.length()==0)
//         {
//             return 0;
//         }
//         if(s.length()==1)
//         {
//             return 1;
//         }
//         //扩充
//         string str="#";
//         int i;
//         for(i=0;i<s.length();i++)
//         {
//             str+=s[i];
//             str+="#";
//         }
//         //#1#2#3#
//         for(i=1;i<str.length();i+=1)
//         {
//             int curr=1;
//             int j=1;
//             while(i-j>=0 && i+j<str.length())
//             {
//                 if(str[i-j]==str[i+j])
//                 {
//                     curr+=2;
//                     j+=1;
//                     length=max(curr,length);
//                 }
//                 else 
//                 {
//                     break;
//                 }

//             }
//         }

//         return length/2;
//     }
// };