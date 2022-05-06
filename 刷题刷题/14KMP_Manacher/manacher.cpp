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


class Manacher {
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
        vector<int> radis_arr(str.length());//回文半径数组!!!!这个是最关键的
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
            //需要验证的区域
            while(i+radis_arr[i]<str.length() && i-radis_arr[i]>-1)
            {
                //可以继续扩充 对应情况1和2.3
                //向外扩充
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
    }
};
// @lc code=end

int main()
{
    Manacher m;
    cout<<m.longestPalindrome("1132310")<<endl;
}


