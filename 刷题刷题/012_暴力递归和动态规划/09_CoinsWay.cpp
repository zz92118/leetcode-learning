#include<iostream>
#include<vector>
using namespace std;

class CoinsWay
{
public:
    int ways(vector<int> arr,int target);//dfs
    int ways2(vector<int> arr,int target);//备忘录dp
    int ways3(vector<int> arr,int target);//枚举行为dp
    int ways4(vector<int> arr,int target);//枚举行为dp 优化枚举行为
    
	// arr[index....] 所有的面值，每一个面值都可以任意选择张数，组成正好rest这么多钱，方法数多少？
    int process(vector<int> arr,int index,int rest);
    int process_dp(vector<int> arr,int index,int rest,vector<vector<int> > &dp);
};


int CoinsWay::ways3(vector<int> arr,int target)
{
    if(arr.size()==0 || target<0)//把边界条件筛选一下
    {
        return 0;
    }

    vector<vector<int> >dp;//初始化没有被访问到
    vector<int> rows;
    int i,j;
    int n=arr.size();
    for(i=0;i<target+1;i++)
    {  
        rows.push_back(0);
    }
    for(i=0;i<arr.size()+1;i++)
    {
        dp.push_back(rows);
    }
    // dp[index][rest]==0? 1:0;
    dp[n][0]=1;//终止条件base case
    //大方向从index+1---index
    //小方向从左到右
    for(int index=n-1;index>=0;index--)
    {
        for(int rest=0;rest<=target;rest++)
        {
            int ways=0;
            for(int papers=0 ; papers*arr[index]<=rest ; papers++)
            {
                ways+=dp[index+1][rest-papers*arr[index]];
            }
            dp[index][rest]=ways;            
        }
    }
    return dp[0][target];
}

int CoinsWay::ways4(vector<int> arr,int target)
{
    if(arr.size()==0 || target<0)//把边界条件筛选一下
    {
        return 0;
    }

    vector<vector<int> >dp;//初始化没有被访问到
    vector<int> rows;
    int i,j;
    int n=arr.size();
    for(i=0;i<target+1;i++)
    {  
        rows.push_back(0);
    }
    for(i=0;i<arr.size()+1;i++)
    {
        dp.push_back(rows);
    }
    // dp[index][rest]==0? 1:0;
    dp[n][0]=1;//终止条件base case
    //大方向从index+1---index
    //小方向从左到右
    for(int index=n-1;index>=0;index--)
    {
        for(int rest=0;rest<=target;rest++)
        {
            //优化枚举算法
            dp[index][rest]=dp[index+1][rest];
            if(rest-arr[index]>=0)
            {
                dp[index][rest]+=dp[index][rest-arr[index]];
            }           
        }
    }
    return dp[0][target];
}


int CoinsWay::ways(vector<int> arr,int target)
{
    if(arr.size()==0 || target<0)//把边界条件筛选一下
    {
        return 0;
    }
    return process(arr,0,target);
}

int CoinsWay::ways2(vector<int> arr,int target)
{
    if(arr.size()==0 || target<0)//把边界条件筛选一下
    {
        return 0;
    }
    vector<vector<int> >dp;//初始化没有被访问到
    vector<int> rows;
    int i,j;
    for(i=0;i<target+1;i++)
    {  
        rows.push_back(-1);
    }
    for(i=0;i<arr.size()+1;i++)
    {
        dp.push_back(rows);
    }

    return process_dp(arr,0,target,dp);
}

int CoinsWay::process_dp(vector<int> arr,int index,int rest,vector<vector<int> > &dp)
{
    if(dp[index][rest]!=-1)
    {
        return dp[index][rest];
    }
    else 
    {
        if(rest<0)//rest上的终止条件
        {
            dp[index][rest]=0;
            return dp[index][rest];
        }
        else 
        {
            if(index==arr.size())//index上的种植条件
            {
                dp[index][rest]==0? 1:0;
            }
            int nums=0;//在数组的i位置 ,剩余rest的时候的方法数
            for(int papers=0;papers*arr[index]<=rest;papers++)
            {
                nums+=process(arr,index+1,rest-papers*arr[index]);
            }
            dp[index][rest]=nums;
            return dp[index][rest];
        }
    }

}


int CoinsWay::process(vector<int> arr,int index,int rest)
{
    if(rest<0)//这个分支其实不会被执行到
    {
        return 0;
    }
    else 
    {
        if(index==arr.size())
        {
            return rest==0? 1:0;//rest=0的时候返回一种可能性
        }
        int nums=0;//在数组的i位置 ,剩余rest的时候的方法数
        for(int papers=0;papers*arr[index]<=rest;papers++)
        {
            nums+=process(arr,index+1,rest-papers*arr[index]);
        }
        return nums;
    }
}


int main()
{
    CoinsWay c;
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(50);
    arr.push_back(100);
    int aim=1000;
    cout<<c.ways(arr,aim)<<endl;
    cout<<c.ways2(arr,aim)<<endl;
    cout<<c.ways3(arr,aim)<<endl;
    cout<<c.ways4(arr,aim)<<endl;
}