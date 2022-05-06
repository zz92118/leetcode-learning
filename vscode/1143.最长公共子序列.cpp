/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

/*
子序列不要求连续的
*/
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp;
        vector<int> curr;
        int i,j;
        for(i=0;i<text2.size();i++)
        {
            curr.push_back(0);
        }
        for(i=0;i<text1.size();i++)
        {
            dp.push_back(curr);
        }
        if(text2[0]==text1[0])
        {
            dp[0][0]=1;
        }
        //初始化第一行第一列
        for(i=1;i<text2.size();i++)
        {
            if(text2[i]==text1[0])
            {
                dp[0][i]=1;
            }
            else 
            {
                dp[0][i]=dp[0][i-1];
            }
        }

        for(i=1;i<text1.size();i++)
        {
            if(text1[i]==text2[0])
            {
                dp[i][0]=1;
            }
            else 
            {
                dp[i][0]=dp[i-1][0];
            }
        }

        for(i=1;i<text1.size();i++)
        {
            for(j=1;j<text2.size();j++)
            {
                int case1=dp[i-1][j-1];
                int case2=dp[i-1][j];
                int case3=dp[i][j-1];
                int case4=dp[i-1][j-1];
                if(text2[j]==text1[i])//必出现第四种情况　
                {
                    case4=dp[i-1][j-1]+1;
                }
                int temp=max(case2,case3);
                dp[i][j]=max(temp,case4);
                
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.longestCommonSubsequence("abc","def")<<endl;
}