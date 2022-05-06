/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        int i;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int dfs(int rest,vector<int> &dp)
    {
        if(dp[rest]!=0)
        {
            return dp[rest];
        }
        else
        {
            if(rest<0)
            {
                return 0;
            }
            if(rest==0)
            {
                return 1;
            }
            if(dp[rest-1] && dp[rest-2])
            {
                dp[rest]=dp[rest-1]+dp[rest-2];
            }
            return dfs(rest-1,dp)+dfs(rest-2,dp);
        }

    }
};
// @lc code=end
int main()
{
    Solution s;
    cout<<s.climbStairs(44);
    return 0;

}

