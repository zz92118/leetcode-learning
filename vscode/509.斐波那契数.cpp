/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

/*

f(n) = 1 (n=1.n=2)
f(n) = f(n-1) + f(n-2) 
状态转移方程
return f(n - 1) + f(n - 2)，dp[i] = dp[i - 1] + dp[i - 2]


*/
class Solution {
public:
    int fib(int n)
    {
        int i;
        vector<int> dp(n+1,-1);
        if(n==0)
        {
            return 0;
        }
        dp[0]=0;
        dp[1]=1;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int fib2(int n) {
        int i;
        if(n==0)
        {
            return 0;
        }
        vector<int> arr(n+1,-1);
        return dp(n,arr);
    }
    //优化方法
    int fib3(int n) {
        if (n == 0 || n == 1) {
            // base case
            return n;
        }
        // 分别代表 dp[i - 1] 和 dp[i - 2]
        int dp_i_1 = 1, dp_i_2 = 0;
        for (int i = 2; i <= n; i++) {
            // dp[i] = dp[i - 1] + dp[i - 2];
            int dp_i = dp_i_1 + dp_i_2;
            // 滚动更新
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i_1;
    }

    int dp(int n,vector<int> &arr)
    {
        //base case

        if(arr[n]!=-1)
        {
            return arr[n];
        }

        if(n==1 || n==2)
        {
            arr[n]=1;
            return 1;
        }

        arr[n]=dp(n-1,arr)+dp(n-2,arr);

        return arr[n];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.fib(10)<<endl;
}
