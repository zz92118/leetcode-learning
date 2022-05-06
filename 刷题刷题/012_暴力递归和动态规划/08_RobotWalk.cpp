#include<vector>
#include<iostream>
using namespace std;
#define x1 7;
#define x2 2;
#define x3 5;
#define x4 3;

class RobotWalk
{
public:
    int nums=0;     

    int ways(int N,int start,int K_steps,int end)
    {
        dfs(N,start,K_steps,end);
        return nums;
    }
    //dfs+dp数组的方法 备忘录 用vector代替数组 
    int ways2(int N,int start,int K_steps,int end);
    //dp的方法  根据弟归写状态转移方程
    int ways3(int N,int start,int K_steps,int end);


    void dfs(int N,int curr,int rest,int end);
    int dfs_dp(int N,int curr,int rest,int end,vector<vector<int> > &dp);
};

int RobotWalk::ways3(int N,int start,int K_steps,int end)
{   
    vector<vector<int> >dp; 
    // curr 1:7
    //rest: 0:5
    int i,j;
    //dp初始化为-1代表没有经历过这个点
    //所有可能的结果都在dp里面
    //代表了当前情况 [curr][rest]即所有的解
    vector<int> rest_dp;
    for(j=0;j<K_steps+1;j++)
    {
        rest_dp.push_back(0);
    }
    for(i=0;i<N+1;i++)
    {
        dp.push_back(rest_dp);
    }

    //根据
    //rest 从1开始到5进行便利
    dp[end][0]=1;
    for(int rest=1;rest<K_steps+1;rest++)
    {
        //1.先填入curr=1的(第一行)
        dp[1][rest]=dp[2][rest-1];
        for(int curr=2;curr<N;curr++)
        {
            dp[curr][rest]=dp[curr-1][rest-1]+dp[curr+1][rest-1];
        }
        dp[N][rest]=dp[N-1][rest-1];
    }
    return dp[start][K_steps];
}

int RobotWalk::ways2(int N,int start,int K_steps,int end)
{
    vector<vector<int> >dp; 
    // curr 1:7
    //rest: 0:5
    int i,j;
    //dp初始化为-1代表没有经历过这个点
    //所有可能的结果都在dp里面
    //代表了当前情况 [curr][rest]即所有的解
    vector<int> rest_dp;
    for(j=0;j<K_steps+1;j++)
    {
        rest_dp.push_back(-1);
    }
    for(i=0;i<N+1;i++)
    {
        dp.push_back(rest_dp);
    }
    
    return dfs_dp(N,start,K_steps,end,dp);
}


int RobotWalk::dfs_dp(int N,int curr,int rest,int end,vector<vector<int> > &dp)
{
    //dp数组中有
    if(dp[curr][rest]>=0)
    {
        return dp[curr][rest];
    }
    //dp数组中没有 ，继续dfs，最后加入数组
    else 
    {
        int ans=0;
        //到终点了
        if(rest==0)
        {
            if(curr==end)
            {
                ans=1;
            }
            else 
            {
                ans=0;
            }
        }
        //得到当前步的值
        else 
        {
            if(curr==1)
            {
                ans = dfs_dp(N,2,rest-1,end,dp);
            }
            else if(curr==N)
            {
                ans = dfs_dp(N,N-1,rest-1,end,dp);
            }
            else 
            {
                ans = dfs_dp(N,curr-1,rest-1,end,dp) + dfs_dp(N,curr+1,rest-1,end,dp);
            }
        }
        //更新dp数组并且return
        dp[curr][rest]=ans;
        return ans;
    }
    
}


void RobotWalk::dfs(int N,int curr,int rest,int end)
{
    if(rest==0)
    {
        //终止条件 rest=0并且到了终点
        if(curr==end)
        {
            nums++;
            return ;
        }

    }
    else 
    {
        //左边界只能向右
        if(curr==1)
        {
            dfs(N,2,rest-1,end);
        }
        //右边界只能向左
        else if(curr==N)
        {
            dfs(N,N-1,rest-1,end);
        }
        //其余情况 左右两边都可以尝试
        else 
        {
            dfs(N,curr-1,rest-1,end);
            dfs(N,curr+1,rest-1,end);
        }
    }
    
}

// int ways3(int N,int start,int K_steps,int end)
// {
//     int dp[7+1][]
// }


int main()
{
    RobotWalk r;
    cout<<r.ways(7,2,5,3)<<endl;
    cout<<r.ways2(7,2,5,3)<<endl;
    cout<<r.ways3(7,2,5,3)<<endl;
    
    //7期盼
    //2起始位置
    //3终止位置
    //5 总共的step
}