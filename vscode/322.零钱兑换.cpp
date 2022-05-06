/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
最优子结构的条件： 每种硬币都是无限使用的 所以子问题之间没有相互制，是互相独立的。

*/
class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-111);
        return dfs(coins,amount,memo);
    }
    int dfs(vector<int>& coins,int amount,vector<int>& memo)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0)
        {
            return -1;
        }
        if(memo[amount]!=-111)
        {
            return memo[amount];
        }
        int i;
        int res=INT_MAX;
        for(i=0;i<coins.size();i++)
        {
            int ways=dfs(coins,amount-coins[i],memo); //子问题的解 再加一种
            if(ways==-1)
            {
                continue;
            }
            res = min(res,ways);//找到coinsways最少的方案
        }
        memo[amount] = (res==INT_MAX )? -1 : res;
        return memo[amount];
    }
};
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);

    Solution s;
    int x=s.coinChange(arr,11);
    cout<<x;
}

